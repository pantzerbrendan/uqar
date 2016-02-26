
#include "factory/Factory.hpp"

namespace Factories
{

    template <typename FactoryName, typename EnumType>
    FactoryBaseType     *Factory::newObject(const EnumType type, const std::string &params)
    {
        return (FactoryName::newObject(type, params));
    }

    FactoryBaseType    *Factory::newObject() { return (new FactoryBaseType()); }

}
