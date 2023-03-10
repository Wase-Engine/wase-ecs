#pragma once

#include <unordered_map>
#include <string>

namespace wase::ecs
{
	class TypeID
	{
	public:
		TypeID() = delete;

		template<typename T>
		static size_t getTypeID();

	private:
		static std::unordered_map<std::string, size_t> m_ComponentTypeIds;
	};
}

#include <type_id.inl>