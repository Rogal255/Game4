template <typename Resource, typename EnumId>
void ResourceHolder<Resource, EnumId>::load(EnumId t_EnumId, const std::string& t_Filename)
{
	std::unique_ptr<Resource> pResource = std::make_unique<Resource>();

	if (!pResource->loadFromFile(t_Filename))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + t_Filename);
	}

	auto insertionResult = m_ResourceMap.insert(std::make_pair(t_EnumId, std::move(pResource)));
	assert(insertionResult.second);
}

template <typename Resource, typename EnumId>
template <typename Parameter>
void ResourceHolder<Resource, EnumId>::load(EnumId t_EnumId, const std::string& t_Filename, const Parameter& t_SecondParameter)
{
	std::unique_ptr<Resource> pResource = std::make_unique<Resource>();

	if (!pResource->loadFromFile(t_Filename, t_SecondParameter))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + t_Filename);
	}

	auto insertionResult = m_ResourceMap.insert(std::make_pair(t_EnumId, std::move(pResource)));
	assert(insertionResult.second);
}

template <typename Resource, typename EnumId>
Resource& ResourceHolder<Resource, EnumId>::get(EnumId t_EnumId)
{
	auto searchResult = m_ResourceMap.find(t_EnumId);
	assert(searchResult != m_ResourceMap.end());
	return *searchResult->second;
}

template <typename Resource, typename EnumId>
const Resource& ResourceHolder<Resource, EnumId>::get(EnumId t_EnumId) const
{
	auto searchResult = m_ResourceMap.find(t_EnumId);
	assert(searchResult != m_ResourceMap.end());
	return *searchResult->second;
}
