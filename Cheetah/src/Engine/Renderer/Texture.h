#ifndef CHEETAH_ENGINE_RENDERER_TEXTURE_H_
#define CHEETAH_ENGINE_RENDERER_TEXTURE_H_

#include <memory>

namespace cheetah
{
	struct CreateTextureParams
	{
		int width;
		int height;
		unsigned char* data = nullptr;
		int nrOfChannels = 3;
	};

	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual void bind() const = 0;
		virtual void unBind() const = 0;

		virtual void addData(void* contents) const = 0;
		
		virtual const unsigned int getId() const = 0;
		virtual const unsigned int getCurrentBound() const = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual int getChannels() const = 0;

	public:
		float scale = 1;
		static std::unique_ptr<Texture> create(const CreateTextureParams& params);
		static Texture* createRaw(const CreateTextureParams& params);
	};
}

#endif // !CHEETAH_ENGINE_RENDERER_TEXTURE_H_
