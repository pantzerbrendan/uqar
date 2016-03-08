
#ifndef FACTORYBASETYPE_HPP_
#define FACTORYBASETYPE_HPP_

#include <string>

namespace Factories
{

    class FactoryBaseType
    {
    protected:
        std::string _typename;

    public:
        FactoryBaseType();
        ~FactoryBaseType();

        const std::string &getType() const;
    };

}

#endif /* !FACTORYBASETYPE_HPP_ */
