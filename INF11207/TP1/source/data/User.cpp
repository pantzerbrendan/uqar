
#include <ostream>
#include <iostream>
#include <string>
#include "data/User.hh"
#include "data/Acronyms.hh"
#include "utils/utils.hh"

static std::string      U_CSVFormatter(const User *);

User        *NewUser(const std::string &firstname, const std::string &lastname, Address *address, Birthdate *birthdate, Acronyms *acr)
{
    User    *user = new User();

    user->firstname = firstname;
    user->lastname = lastname;
    user->address = address;
    user->birthdate = birthdate;
    user->acronyms = acr;

    /** function pointer initialization */
    user->CSVFormatter = &U_CSVFormatter;
    return (user);
}

User        *NewUser(const std::string &str)
{
    std::string *array = my_string::split(str, ';');
    Birthdate   *date = NewBirthdate(array[6]);
    Address     *address = NewAddress(array[2], array[3], array[4], array[5]);
    Acronyms    *acronyms = NewAcronyms(array[7]);
    User        *user = NewUser(array[0], array[1], address, date, acronyms);

    delete[] array;
    if (!user || !address || !date || !acronyms)
    {
        if (user) delete user;
        if (address) delete address;
        if (date) delete date;
        if (acronyms) delete acronyms;
        return (NULL);
    }
    return (user);
}

void        DeleteUser(User *usr)
{
    if (usr)
    {
        DeleteAddress(usr->address);
        DeleteBirthdate(usr->birthdate);
        AcronymsDestroy(usr->acronyms);
        delete usr;
        usr = NULL;
    }
}

std::ostream    &operator<<(std::ostream &stream, const User &usr)
{
    stream << usr.firstname << " ";
    stream << usr.lastname << ", ";
    stream << *(usr.address) << ", ";
    stream << *(usr.birthdate) << ", ";
    stream << *(usr.acronyms);
    return (stream);
}

static std::string      U_CSVFormatter(const User *usr)
{
    std::string result = usr->firstname + ";" + usr->lastname;
    result += ";" + usr->address->CSVFormatter(usr->address);
    result += ";" + usr->birthdate->CSVFormatter(usr->birthdate);
    result += ";" + usr->acronyms->CSVFormatter(usr->acronyms);
    return (result);
}
