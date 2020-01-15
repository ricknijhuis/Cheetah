#ifndef GAME_GAMEOBJECT_H_ 
#define GAME_GAMEOBJECT_H_

#include "Cheetah.h"

namespace game
{
	struct GameObjectParams
	{
		cheetah::math::Vector3f position = cheetah::math::Vector3f(0.0f);
		cheetah::math::Vector3f scale = cheetah::math::Vector3f(1.0f);
		cheetah::math::Quaternionf rotation = cheetah::math::Quaternionf();
		cheetah::math::Vector4f color = cheetah::math::Vector4f(1.0f);
		cheetah::Texture* texture = nullptr;
	};

	class GameObject
	{
	public:
		GameObject(const GameObjectParams& params);

		void setTexture(cheetah::Texture* texture);
		void setScale(const cheetah::math::Vector3f& scale);
		void setPosition(const cheetah::math::Vector3f& position);
		void translate(const cheetah::math::Vector3f& position);
		void draw();
	public:
		cheetah::Texture* m_texture = nullptr;
		cheetah::math::Quaternionf m_rotation;
		cheetah::math::Vector3f m_position;
		cheetah::math::Vector3f m_scale;
		cheetah::math::Vector4f m_color;
	};
}

#endif // !GAME_GAMEOBJECT_H_ 
