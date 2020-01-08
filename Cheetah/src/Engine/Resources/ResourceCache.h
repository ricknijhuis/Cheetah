#ifndef CHEETAH_ENGINE_RESOURCES_RESOURCECACHE_H_
#define CHEETAH_ENGINE_RESOURCES_RESOURCECACHE_H_

#include <string>
#include <unordered_map>
#include <memory>

namespace cheetah
{
	template<typename T>
	class ResourceCache
	{
	public:
		ResourceCache() = default;
		~ResourceCache() = default;

		void free();
		void free(const std::string& name);

		template<typename... Args>
		void add(const std::string& name, Args... args);
		void add(const std::string& name, std::unique_ptr<T> content);

		bool contains(const std::string& name) const;
		T& getCachedElementRef(const std::string& name) const;
		T* getCachedElementPtr(const std::string& name) const;
	private:
		static std::unordered_map<std::string, std::unique_ptr<T>>* m_cache;
	};
}

#include "ResourceCache.inl"

#endif // !CHEETAH_ENGINE_RESOURCES_RESOURCECACHE_H_
