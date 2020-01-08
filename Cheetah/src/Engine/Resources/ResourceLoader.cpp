#include "ResourceLoader.h"

#include <stb_image.h>

#include <iostream>
#include <fstream>
#include <sstream>

namespace cheetah
{
	std::unique_ptr<ResourceCache<Shader>> ResourceLoader::s_shaderCache = std::make_unique<ResourceCache<Shader>>();
	std::unique_ptr<ResourceCache<Texture>> ResourceLoader::s_textureCache = std::make_unique<ResourceCache<Texture>>();

	Shader& ResourceLoader::getShader(const std::string& filePath)
	{
		const std::string resourceName = getResourceName(filePath);

		if(s_shaderCache->contains(resourceName))
			return s_shaderCache->getCachedElementRef(resourceName);

		s_shaderCache->add(resourceName, Shader::create(readFileToString(filePath)));

		return s_shaderCache->getCachedElementRef(resourceName);
	}

	Shader* ResourceLoader::getShaderPtr(const std::string& filePath)
	{
		const std::string resourceName = getResourceName(filePath);

		if (s_shaderCache->contains(resourceName))
			return s_shaderCache->getCachedElementPtr(resourceName);

		s_shaderCache->add(resourceName, Shader::create(readFileToString(filePath)));

		return s_shaderCache->getCachedElementPtr(resourceName);
	}

	Shader& ResourceLoader::getShader(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		const std::string fileNameVert = getResourceName(vertFilePath);
		const std::string fileNameFrag = getResourceName(fragFilePath);
		const std::string resourceName = fileNameVert + fileNameFrag;

		if(s_shaderCache->contains(resourceName))
			return s_shaderCache->getCachedElementRef(resourceName);

		s_shaderCache->add(fileNameVert + fileNameFrag, Shader::create(readFileToString(vertFilePath), readFileToString(fragFilePath)));

		return s_shaderCache->getCachedElementRef(resourceName);
	}

	Shader* ResourceLoader::getShaderPtr(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		const std::string fileNameVert = getResourceName(vertFilePath);
		const std::string fileNameFrag = getResourceName(fragFilePath);
		const std::string resourceName = fileNameVert + fileNameFrag;

		if (s_shaderCache->contains(resourceName))
			return s_shaderCache->getCachedElementPtr(resourceName);

		s_shaderCache->add(fileNameVert + fileNameFrag, Shader::create(readFileToString(vertFilePath), readFileToString(fragFilePath)));

		return s_shaderCache->getCachedElementPtr(resourceName);
	}

	Texture& ResourceLoader::getTexture(const std::string& filePath, const bool& flip)
	{
		const std::string resourceName = getResourceName(filePath);

		if (s_textureCache->contains(resourceName))
			return s_textureCache->getCachedElementRef(resourceName);

		addTexture(resourceName, filePath, flip);

		return s_textureCache->getCachedElementRef(resourceName);
	}

	Texture* ResourceLoader::getTexturePtr(const std::string& filePath, const bool& flip)
	{
		const std::string resourceName = getResourceName(filePath);

		if (s_textureCache->contains(resourceName))
			return s_textureCache->getCachedElementPtr(resourceName);

		addTexture(resourceName, filePath, flip);

		return s_textureCache->getCachedElementPtr(resourceName);
	}

	std::string ResourceLoader::readFileToString(const std::string& filePath)
	{
		std::string content = "";
		std::ifstream fileStream(filePath, std::ios::in);

		if (!fileStream.is_open())
			std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;

		std::string line = "";
		while (!fileStream.eof())
		{
			std::getline(fileStream, line);
			content.append(line + "\n");
		}

		fileStream.close();
		return content;
	}

	std::string ResourceLoader::getResourceName(const std::string& filePath)
	{
		return filePath.substr(filePath.find_last_of("/\\") + 1);
	}

	std::string ResourceLoader::getResourceName(const std::string& filePath, const std::string& filePath2)
	{
		return filePath.substr(filePath.find_last_of("/\\") + 1) + filePath2.substr(filePath.find_last_of("/\\") + 1);
	}

	void ResourceLoader::addTexture(const std::string& resourceName, const std::string& filePath, const bool& flip)
	{
		int width, height, nrChannels;

		if (flip)
			stbi_set_flip_vertically_on_load(1);

		unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, STBI_rgb_alpha);

		s_textureCache->add(resourceName, Texture::create({ width, height, data, nrChannels }));

		stbi_image_free(data);
	}
}
