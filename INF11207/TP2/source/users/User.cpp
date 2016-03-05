
#include "users/User.hpp"

User::User(const std::string &params)
{
    // add data

    #ifdef DEBUG
    std::cout << this->_firstname << " " << this->_lastname << " has been created" << std::endl;
    #endif
}

User::~User()
{
    delete this->_birthdate;
}

const std::string   &User::getFirstname() const { return (this->_firstname); }
const std::string   &User::getLastname() const { return (this->_lastname); }
Date                *User::getBirthDate() const { return (this->_birthdate); }
