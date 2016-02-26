
#include <typeinfo>
#include <iostream>
#include "factory/FactoryBaseType.hpp"

namespace Factories {

    FactoryBaseType::FactoryBaseType()
    {
        this->_typename = typeid(*this).name();

        #ifdef DEBUG
        std::clog << this->_typename << " has been created" << std::endl;
        #endif
    }

    FactoryBaseType::~FactoryBaseType()
    {
        #ifdef DEBUG
        std::clog << this->_typename << " has been destroyed" << std::endl;
        #endif
    }

}
