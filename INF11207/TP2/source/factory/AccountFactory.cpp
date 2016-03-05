
#include "factory/AccountFactory.hpp"

Account     *AccountFactory::newObject(const AccountEnum e, const std::string &params)
{
    switch (e) {
        case REGULAR: return new RegularAccount(params);
        case CHILD: return new ChildAccount(params);
        case RETIREMENT: return new RetirementAccount(params);
        default: return AccountFactory::newObject();
    }
}

Account     *AccountFactory::newObject()
{
    return new Account();
}
