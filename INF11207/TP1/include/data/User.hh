
#pragma once

#include <string>
#include <ostream>
#include "Birthdate.hh"
#include "Address.hh"
#include "Acronyms.hh"

typedef struct s_user
{
    std::string firstname;
    std::string lastname;
    Address     *address;
    Birthdate   *birthdate;
    //sigles de cours
    Acronyms    *acronyms;

    std::string (*CSVFormatter)(const struct s_user *);
}               User;

User            *NewUser(const std::string &, const std::string &, Address *, Birthdate *, Acronyms *);
User            *NewUser(const std::string &);
void            DeleteUser(User *);

std::ostream    &operator<<(std::ostream &, const User &);
