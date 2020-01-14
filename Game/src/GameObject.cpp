#include "GameObject.h"

using namespace cheetah;
using namespace math;

namespace game
{
	GameObject::GameObject(const GameObjectParams& params)
		: m_position(params.position.x, params.position.y, params.position.z),
		m_scale(params.scale.x, params.scale.y, params.scale.z),
		m_rotation(),
		m_texture(params.texture),
		m_color(params.color.x, params.color.y, params.color.z, params.color.w)
	{
	}

	void GameObject::setTexture(cheetah::Texture* texture)
	{
		m_texture = texture;
	}

	void GameObject::setPosition(const Vector3f& position)
	{
		m_position.x = position.x;
		m_position.y = position.y;
		m_position.z = position.z;
	}

	void GameObject::setScale(const Vector3f& scale)
	{
		m_scale.x = scale.x;
		m_scale.y = scale.y;
		m_scale.z = scale.z;
	}

	void GameObject::translate(const Vector3f& position)
	{
		m_position.x += position.x;
		m_position.y += position.y;
		m_position.z += position.z;
	}

	void GameObject::draw()
	{
		if (m_texture != nullptr)
		{
			Renderer2D::drawQuad(DrawTexturedQuadParams{ m_position, m_scale, m_rotation, m_color, m_texture });
		}
		else
		{
			Renderer2D::drawQuad(DrawQuadParams{ m_position, m_scale, m_rotation, m_color });
		}
	}
}