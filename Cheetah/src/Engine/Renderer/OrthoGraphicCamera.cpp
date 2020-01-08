#include "OrthoGraphicCamera.h"

namespace cheetah
{
	OrthoGraphicCamera::OrthoGraphicCamera(const OrthoGraphicCameraParams& params)
		:
		m_projectionMatrix(Mat4x4f::ortho(params.aspectRatio * params.left, params.aspectRatio * params.right, params.top, params.bottom, params.zNear, params.zFar, params.aspectRatio).get()),
		m_viewMatrix(Mat4x4f::translate(Mat4x4f(1.0f), params.position)),
		m_viewProjectionMatrix(m_projectionMatrix* m_viewMatrix),
		m_position(params.position),
		m_left(params.left),
		m_right(params.right),
		m_bottom(params.bottom),
		m_top(params.top),
		m_zFar(params.zFar),
		m_zNear(params.zNear)
	{
	}

	Mat4x4<float> OrthoGraphicCamera::getViewProjectionMatrix() const
	{
		return this->m_viewProjectionMatrix;
	}

	Mat4x4<float> OrthoGraphicCamera::getProjectionMatrix() const
	{
		return this->m_projectionMatrix;
	}

	Mat4x4<float> OrthoGraphicCamera::getViewMatrix() const
	{
		return this->m_viewMatrix;
	}

	void OrthoGraphicCamera::translate(const Vector3f& position)
	{
		m_position.x = position.x; 
		m_position.y = position.y; 
		m_position.z = position.z;
		m_viewMatrix = Mat4x4f::translate(m_viewMatrix, position);
		recalculateViewProjectionMatrix();
	}

	void OrthoGraphicCamera::setPosition(const Vector3f& position)
	{
		m_position.x = position.x;
		m_position.y = position.y;
		m_position.z = position.z;
		m_viewMatrix = Mat4x4f::translate(Mat4x4f(), position);
		recalculateViewProjectionMatrix();
	}

	void OrthoGraphicCamera::recalculateViewProjectionMatrix()
	{
		m_viewProjectionMatrix = m_projectionMatrix * m_viewMatrix;
	}

	bool OrthoGraphicCamera::onWindowResize(WindowResizeEvent& event)
	{
		float aspectRatio = (float)event.m_width / (float)event.m_height;

		m_projectionMatrix = Mat4x4f::ortho(aspectRatio * m_left, aspectRatio * m_right, m_top, m_bottom, m_zNear, m_zFar, aspectRatio).get();
		
		recalculateViewProjectionMatrix();

		return true;
	}
}