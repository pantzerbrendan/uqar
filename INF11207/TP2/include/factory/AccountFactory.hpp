
#ifndef ACCOUNTFACTORY_HPP_
#define ACCOUNTFACTORY_HPP_

#include <string>
#include "Accounts/A_Account.hh"

typedef enum { REGULAR, CHILD, RETIREMENT } AccountEnum;

class AccountFactory {
private:
    AccountFactory();
    virtual ~AccountFactory ();

public:
    static A_Account  *newObject(const AccountEnum, const std::string & = "");
    static A_Account  *newObject();

};

#endif /* ACCOUNTFACTORY_HPP_ */
