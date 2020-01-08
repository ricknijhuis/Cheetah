#ifndef GAME_GAMEOBJECT_H_ 
#define GAME_GAMEOBJECT_H_

#include "Cheetah.h"

namespace game
{
	struct GameObjectParams
	{
		cheetah::Vector3f position = cheetah::Vector3f(0.0f);
		cheetah::Vector3f scale = cheetah::Vector3f(1.0f);
		cheetah::Quaternion rotation = cheetah::Quaternion();
		cheetah::Vector4f color = cheetah::Vector4f(1.0f);
		cheetah::Texture* texture = nullptr;
	};

	class GameObject
	{
	public:
		GameObject(const GameObjectParams& params);

		void setTexture(cheetah::Texture* texture);
		void setScale(const cheetah::Vector3f& scale);
		void setPosition(const cheetah::Vector3f& position);
		void translate(const cheetah::Vector3f& position);
		void draw();
	public:
		cheetah::Texture* m_texture = nullptr;
		cheetah::Quaternion m_rotation;
		cheetah::Vector3f m_position;
		cheetah::Vector3f m_scale;
		cheetah::Vector4f m_color;
	};
}

#endif // !GAME_GAMEOBJECT_H_ 
