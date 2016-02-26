
#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <string>
#include "FactoryBaseType.hpp"

namespace Factories
{

    class Factory
    {
    private:
        Factory() {}
        virtual ~Factory() {}

    public:
        /*
        ** Template :
        **  - FactoryName : name of the factory to call
        **  - EnumType : type of the enum used by `FactoryName` to create a new object
        */
        template <typename FactoryName, typename EnumType>
        static FactoryBaseType *newObject(const EnumType, const std::string & = "");

        /* Creates a new FactoryBaseType object instance */
        static FactoryBaseType *newObject();
    };

}

#endif /* !FACTORY_HPP_ */
