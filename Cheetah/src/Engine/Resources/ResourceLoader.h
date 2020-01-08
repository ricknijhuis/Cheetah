#ifndef CHEETAH_ENGINE_RESOURCES_RESOURCELOADER_H_
#define CHEETAH_ENGINE_RESOURCES_RESOURCELOADER_H_

#include "Core/Core.h"
#include "ResourceCache.h"
#include "Renderer/Shader.h"
#include "Renderer/Texture.h"

#include <string>

namespace cheetah
{
	class CH_API ResourceLoader
	{
	public:
		/// <summary>Gets shader either from cache or file</summary>
		/// <param name='filePath'>Path to file, file name is used as Id in cache</param>
		/// <returns>Ref: class Shader</returns>
		Shader& getShader(const std::string& filePath);

		/// <summary>Gets shader either from cache or file</summary>
		/// <param name='filePath'>Path to file, file name is used as Id in cache</param>
		/// <returns>Ptr: class Shader</returns>
		Shader* getShaderPtr(const std::string& filePath);

		/// <summary>Gets shader either from cache or file</summary>
		/// <param name='vertFilePath'>Path to vertex shader file, file name is used as Id in cache</param>
		/// <param name='fragFilePath'>Path to fragment shader file, file name is used as Id in cache</param>
		/// <returns>Ref: class Shader</returns>
		Shader& getShader(const std::string& vertFilePath, const std::string& fragFilePath);

		/// <summary>Gets shader either from cache or file</summary>
		/// <param name='vertFilePath'>Path to vertex shader file, file name is used as Id in cache</param>
		/// <param name='fragFilePath'>Path to fragment shader file, file name is used as Id in cache</param>
		/// <returns>Ptr: class Shader</returns>
		Shader* getShaderPtr(const std::string& vertFilePath, const std::string& fragFilePath);

		/// <summary>Gets texture either from cache or file</summary>
		/// <param name='filePath'>Path to texture file, file name is used as Id in cache</param>
		/// <returns>Ref: class Texture</returns>
		Texture& getTexture(const std::string& filePath, const bool& flip = false);

		/// <summary>Gets texture either from cache or file</summary>
		/// <param name='filePath'>Path to texture file, file name is used as Id in cache</param>
		/// <returns>Ptr: class Texture</returns>
		Texture* getTexturePtr(const std::string& filePath, const bool& flip = false);


	private:
		std::string getResourceName(const std::string& filePath);
		std::string getResourceName(const std::string& filePath, const std::string& filePath2);

		std::string readFileToString(const std::string& filename);

		void addTexture(const std::string& resourceName, const std::string& filePath, const bool& flip);

		static std::unique_ptr<ResourceCache<Shader>> s_shaderCache;
		static std::unique_ptr<ResourceCache<Texture>> s_textureCache;
	};
}

#endif // !CHEETAH_ENGINE_RESOURCES_RESOURCELOADER_H_
