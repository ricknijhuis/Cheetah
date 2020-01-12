#ifndef CHEETAH_ENGINE_RENDERER_RENDERER2D_H_
#define CHEETAH_ENGINE_RENDERER_RENDERER2D_H_

#include "Core/Core.h"

#include "OrthoGraphicCamera.h"
#include "Math/Vector3.h"
#include "Math/Quaternion.h"
#include "Texture.h"

#include <memory>

// TODO: move to dynamic buffer for storage
namespace cheetah
{
	struct DrawQuadParams
	{
		Vector3f position;
		Vector3f scale;
		Quaternionf rotation;
		Vector4f color;
	};

	struct DrawTexturedQuadParams
	{
		Vector3f position;
		Vector3f scale;
		Quaternionf rotation;
		Vector4f color;
		Texture* texture = nullptr;
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
		static void addToScene();
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
