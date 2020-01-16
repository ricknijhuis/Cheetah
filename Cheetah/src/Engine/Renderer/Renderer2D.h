#ifndef CHEETAH_ENGINE_RENDERER_RENDERER2D_H_
#define CHEETAH_ENGINE_RENDERER_RENDERER2D_H_

#include "Core/Core.h"

#include "OrthoGraphicCamera.h"
#include "Math/Vector3.h"
#include "Math/Rgba.h"
#include "Math/Quaternion.h"
#include "Renderer2DQueue.h"
#include "Texture.h"

#include <memory>

// TODO: move to dynamic buffer for storage
namespace cheetah
{
	struct DrawQuadParams
	{
		math::Vector3f position;
		math::Vector3f scale;
		math::Quaternionf rotation;
		math::Rgba color;
	};

	struct DrawTexturedQuadParams
	{
		math::Vector3f position;
		math::Vector3f scale;
		math::Quaternionf rotation;
		math::Rgba color;
		Texture* texture = nullptr;
	};

	struct AddToSceneParams
	{
		math::Vector3f position;
		math::Vector3f scale;
		math::Quaternionf rotation;
		math::Rgba color;
		Texture* texture = nullptr;
		Shader* shader = nullptr;
	};

	class CH_API Renderer2D
	{
	public:
		//initializes static render data
		static void init();
		// Begins scene by setting up camera
		static void beginScene(const OrthoGraphicCamera& camera);
		// Ends scene
		static void endScene();
		// adds to scene for use in combination with draw scene
		static void addToScene(const AddToSceneParams& params);
		// directly draws quad
		static void drawQuad(const DrawQuadParams& params);
		static void drawQuad(const DrawTexturedQuadParams& params);
		// draws all cached elements on a efficient way with z sorting, should be called at the end of the loop to draw all updates
		static void drawScene();
		// deletes render cache
		static void shutDown();
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_RENDERER_H_
