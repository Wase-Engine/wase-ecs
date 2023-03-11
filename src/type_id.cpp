#include <type_id.h>

namespace wase::ecs
{
	std::unordered_map<std::string, size_t> TypeID::m_ComponentTypeIds;
}