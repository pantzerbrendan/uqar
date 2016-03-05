
#ifndef ACCOUNTFACTORY_HPP_
#define ACCOUNTFACTORY_HPP_

#include <string>

typedef enum { REGULAR, CHILD, RETIREMENT } AccountEnum;

class AccountFactory {
private:
    AccountFactory();
    virtual ~AccountFactory ();

public:
    static Account  *newObject(const AccountEnum, const std::string & = "");
    static Account  *newObject();

};

#endif /* ACCOUNTFACTORY_HPP_ */
