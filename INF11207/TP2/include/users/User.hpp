
#ifndef USER_HPP_
#define USER_HPP_

#include <string>
#include "Date.hpp"

class User {
private:
    std::string     _firstname;
    std::string     _lastname;
    Date            *_birthdate;

public:
    User();
    virtual ~User ();

};

#endif /* !USER_HPP_ */
