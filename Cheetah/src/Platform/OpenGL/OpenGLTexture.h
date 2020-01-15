#ifndef CHEETAH_PLATFORM_OPENGL_OPENGLTEXTURE_H_
#define CHEETAH_PLATFORM_OPENGL_OPENGLTEXTURE_H_

#include "Renderer/Texture.h"

namespace cheetah
{
	namespace opengl
	{
		class OpenGLTexture : public Texture
		{
		public:
			OpenGLTexture(const CreateTextureParams& params);
			~OpenGLTexture();

			void bind() const override;
			void unBind() const override;

			void addData(void* contents) const override;

			const unsigned int getId() const override;
			const unsigned int getCurrentBound() const override;
			int getWidth() const override;
			int getHeight() const override;
			int getChannels() const override;

		private:
			int convertChannel(short int nrOfChannels);

		private:
			unsigned int m_id;
			int m_width, m_height, m_channels;
			static unsigned int s_currentBound;
		};
	}
}

#endif // !CHEETAH_PLATFORM_OPENGL_OPENGLTEXTURE_H_
