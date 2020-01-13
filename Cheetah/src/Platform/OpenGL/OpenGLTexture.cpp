#include "OpenGLTexture.h"

#include <glad/glad.h>

namespace cheetah
{
	namespace opengl
	{
		OpenGLTexture::OpenGLTexture(const CreateTextureParams& params)
			: m_width(params.width), m_height(params.height), m_channels(convertChannel(params.nrOfChannels))
		{
			glGenTextures(1, &m_id);
			glBindTexture(GL_TEXTURE_2D, m_id);
			glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, m_width, m_height);

			if (params.data)
			{
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, this->m_width, this->m_height, GL_RGBA, GL_UNSIGNED_BYTE, params.data);
				glGenerateMipmap(GL_TEXTURE_2D);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			}
		}

		OpenGLTexture::~OpenGLTexture()
		{
			glDeleteTextures(1, &m_id);
		}

		void OpenGLTexture::bind() const
		{
			glBindTexture(GL_TEXTURE_2D, m_id);
		}

		void OpenGLTexture::unBind() const
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		void OpenGLTexture::addData(void* contents) const
		{
			glBindTexture(GL_TEXTURE_2D, m_id);
			glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, this->m_width, this->m_height, GL_RGB, GL_UNSIGNED_INT, contents);
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		const unsigned int OpenGLTexture::getId() const
		{
			return m_id;
		}

		int OpenGLTexture::getWidth() const
		{
			return m_width;
		}

		int OpenGLTexture::getHeight() const
		{
			return m_height;
		}

		int OpenGLTexture::getChannels() const
		{
			return m_channels;
		}

		int OpenGLTexture::convertChannel(short int channels)
		{
			switch (channels)
			{
			case 3:		return GL_RGB;
			case 4:		return GL_RGBA;
			default:
				return GL_NONE;
			}
		}
	}
}