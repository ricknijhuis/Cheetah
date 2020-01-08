namespace cheetah
{
	template<typename T>
	std::unordered_map<std::string, std::unique_ptr<T>>* ResourceCache<T>::m_cache = new std::unordered_map<std::string, std::unique_ptr<T>>;

	template<typename T>
	void ResourceCache<T>::add(const std::string& name, std::unique_ptr<T> content)
	{
		m_cache->try_emplace(name, std::move(content));
	}

	template<typename T>
	template<typename... Args>
	void ResourceCache<T>::add(const std::string& name, Args... args)
	{
		m_cache->try_emplace(name, std::make_unique<T>(args...));
	}

	template<typename T>
	T& ResourceCache<T>::getCachedElementRef(const std::string& name) const
	{
		auto it = m_cache->find(name);

		if(it != m_cache->end())
			return *it->second;

		throw "resource not found";
	}

	template<typename T>
	T* ResourceCache<T>::getCachedElementPtr(const std::string& name) const
	{
		auto it = m_cache->find(name);

		if (it != m_cache->end())
			return it->second.get();

		throw "resource not found";
	}

	template<typename T>
	bool ResourceCache<T>::contains(const std::string& name) const
	{
		return m_cache->count(name);
	}

	template<typename T>
	void ResourceCache<T>::free()
	{
		m_cache->clear();
	}

	template<typename T>
	void ResourceCache<T>::free(const std::string& name)
	{
		m_cache->erase(name);
	}
}
