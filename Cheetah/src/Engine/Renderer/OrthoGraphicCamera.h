#ifndef CHEETAH_ENGINE_RENDERER_ORHOGRAPHICCAMERA_H_
#define CHEETAH_ENGINE_RENDERER_ORHOGRAPHICCAMERA_H_

#include "Core/Core.h"
#include "Math/Mat4x4.h"
#include "Math/Vector3.h"
#include "Events/ApplicationEvents.h"

namespace cheetah
{
	struct OrthoGraphicCameraParams
	{
		const float left;
		const float right;
		const float top;
		const float bottom;
		const float zNear = -1.0f;
		const float zFar = 1.0f;
		const float aspectRatio;
		math::Vector3f position = math::Vector3f(0.0f);
	};


	class CH_API OrthoGraphicCamera
	{
	public:
		OrthoGraphicCamera(const OrthoGraphicCameraParams& params);

		math::Mat4x4f getViewProjectionMatrix() const;
		math::Mat4x4f getProjectionMatrix() const;
		math::Mat4x4f getViewMatrix() const;

		void translate(const math::Vector3f& position);
		void setPosition(const math::Vector3f& position);

		bool onWindowResize(WindowResizeEvent& event);

	private:
		void recalculateViewProjectionMatrix();

	private:
		float m_left;
		float m_right;
		float m_top;
		float m_bottom;
		float m_zNear;
		float m_zFar;
		math::Vector3f m_position;
		math::Mat4x4f m_projectionMatrix;
		math::Mat4x4f m_viewMatrix;
		math::Mat4x4f m_viewProjectionMatrix;
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_ORHOGRAPHICCAMERA_H_
