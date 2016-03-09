
#ifndef USER_HPP_
#define USER_HPP_

#include <string>
#include <sstream>
#include <iostream>
#include "utils/Date.hpp"

class User
{
private:
    std::string     _firstname;
    std::string     _lastname;
    Date            *_birthdate;

public:
    User(const std::string &, const std::string &, Date *);
    User(const std::string &);
    virtual ~User ();

    const std::string   &getFirstname() const;
    const std::string   &getLastname() const;
    Date                *getBirthDate() const;
};

#endif /* !USER_HPP_ */
