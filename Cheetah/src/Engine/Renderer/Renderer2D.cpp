#include "Renderer2D.h"

#include <glad/glad.h>
#include "RenderAPI.h"
#include "RenderAction.h"
#include "Shader.h"
#include "VertexArray.h"
#include "Resources/ResourceLoader.h"

namespace cheetah
{
	struct RenderData
	{
		std::shared_ptr<VertexArray> vertexArray;
		std::shared_ptr<IndexBuffer> indexBuffer;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::unique_ptr<Texture> texture;
		Shader* shader;
	};

	struct RenderItem
	{
		Texture& texture;
		Shader& shader;
		std::vector<Mat4x4f> transforms;
	};

	static RenderData* s_data;

	void Renderer2D::init()
	{
		ResourceLoader resourceLoader;
		Shader* defaultShader = resourceLoader.getShaderPtr("C:/Users/RickNijhuis/source/repos/Cheetah/Game/assets/texture.vert", "C:/Users/RickNijhuis/source/repos/Cheetah/Game/assets/texture.frag");

		float vertices[] = {
			// positions         // texture coords
			 0.5f,  0.5f, 0.0f,  1.0f, 1.0f,   // top right
			 0.5f, -0.5f, 0.0f,  1.0f, 0.0f,   // bottom right
			-0.5f, -0.5f, 0.0f,  0.0f, 0.0f,   // bottom left
			-0.5f,  0.5f, 0.0f,  0.0f, 1.0f   // top left 
		};

		unsigned int indices[] = {
			0, 1, 3,   // 1
			1, 2, 3    // 2
		};

		s_data = new RenderData;

		std::shared_ptr<VertexArray> VAO = VertexArray::create();
		std::shared_ptr<VertexBuffer> VBO = VertexBuffer::create();
		std::shared_ptr<IndexBuffer> IBO = IndexBuffer::create();

		VBO->addData(vertices, sizeof(vertices));

		IBO->addData(indices, sizeof(indices), 6);

		VertexBufferLayout layout;
		layout.addElement(Shader::ShaderTypes::Float3, false);
		layout.addElement(Shader::ShaderTypes::Float2, false);

		VBO->setLayout(layout);

		VAO->addBuffer(VBO);
		VAO->addBuffer(IBO);

		s_data->vertexArray = VAO;
		s_data->indexBuffer = IBO;
		s_data->vertexBuffer = VBO;
		s_data->shader = defaultShader;
		s_data->texture = Texture::create({ 1, 1 });

		unsigned int textureData = 0xffffffff;
		s_data->texture->addData(&textureData);

		s_data->shader->use();
		s_data->shader->setInt("u_Texture", 0);
		s_data->shader->setFloat4("u_Color", 0.0f, 0.0f, 0.0f, 0.0f);
	}

	void Renderer2D::beginScene(const OrthoGraphicCamera& camera)
	{
		s_data->shader->use();
		s_data->shader->setMat4f("u_ViewProjection", false, &(*camera.getViewProjectionMatrix().get().begin()));
	}

	void Renderer2D::endScene()
	{
	}

	void Renderer2D::drawQuad(const DrawQuadParams& params)
	{
		s_data->texture->bind();
		Mat4x4f transform = Mat4x4f::translate(Mat4x4f(1.0f), params.position) * Mat4x4f::scale(params.scale) * params.rotation.getMatrix();

		s_data->shader->setFloat4("u_Color", params.color.x, params.color.y, params.color.z, params.color.w);
		s_data->shader->setMat4f("u_Transform", true, &(*transform.get().begin()));
		s_data->shader->setFloat("u_Scale", 1.0f);

		s_data->vertexArray->bind();

		RenderAction::drawIndexed(6, RenderAPI::APITypes::UInt);
	}

	void Renderer2D::drawQuad(const DrawTexturedQuadParams& params)
	{
		params.texture->bind();

		Mat4x4f transform = Mat4x4f::translate(Mat4x4f(1.0f), params.position) * Mat4x4f::scale(params.scale) * params.rotation.getMatrix();

		s_data->shader->setFloat4("u_Color", params.color.x, params.color.y, params.color.z, params.color.w);
		s_data->shader->setMat4f("u_Transform", true, &(*transform.get().begin()));
		s_data->shader->setFloat("u_Scale", params.texture->scale);

		s_data->vertexArray->bind();

		RenderAction::drawIndexed(6, RenderAPI::APITypes::UInt);
	}

	void Renderer2D::shutDown()
	{
		delete s_data;
	}
}