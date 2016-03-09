
#include "factory/AccountFactory.hpp"

Account     *AccountFactory::newObject(const AccountEnum e, const std::string &params)
{
    // std::map<std::string, std::string> map;
    // std::istringstream iss(params);
    // map["id"] = std::getline(iss, tmp, ',');
    // for (int i = 0; i < 4; i++);
    //     std::getline(iss, tmp, ',');
    // map["idFather"] = std::getline(iss, tmp, ',');
    // map["balance"] = std::getline(iss, tmp, ',');


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
