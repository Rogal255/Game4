#pragma once

// #define NDEBUG - uncomment it to disable assertions

#include <map>
#include <memory>
#include <string>
#include <cassert>

enum class GameTextures
{
	Ship,
	Missle,
};

template <typename Resource, typename EnumId>
class ResourceHolder
{
	std::map<EnumId, std::unique_ptr<Resource>> m_ResourceMap;

public:
	void load(EnumId t_EnumId, const std::string& t_Filename);
	template <typename Parameter>
	void load(EnumId t_EnumId, const std::string& t_Filename, const Parameter& t_SecondParameter);
	Resource& get(EnumId t_EnumId);
	const Resource& get(EnumId t_EnumId) const;
};

#include "ResourceHolder.inl"
