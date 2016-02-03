
#include <ostream>
#include <iostream>
#include <string>
#include "data/User.hh"
#include "utils/utils.hh"

static std::string      U_CSVFormatter(const User *);

User        *NewUser(const std::string &firstname, const std::string &lastname, Address *address, Birthdate *birthdate)
{
    User    *user = new User();

    user->firstname = firstname;
    user->lastname = lastname;
    user->address = address;
    user->birthdate = birthdate;

    /** function pointer initialization */
    user->CSVFormatter = &U_CSVFormatter;
    return (user);
}

User        *NewUser(const std::string &str)
{
    std::string *array = my_string::split(str, ';');
    Birthdate   *date = NewBirthdate(array[6]);
    Address     *address = NewAddress(array[2], array[3], array[4], array[5]);
    User        *user = NewUser(array[0], array[1], address, date);

    delete[] array;
    if (!user || !address || !date)
    {
        if (user) delete user;
        if (address) delete address;
        if (date) delete date;
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
    //stream << usr->;
    return (stream);
}

static std::string      U_CSVFormatter(const User *usr)
{
    std::string result = usr->firstname + ";" + usr->lastname;
    result += ";" + usr->address->CSVFormatter(usr->address);
    result += ";" + usr->birthdate->CSVFormatter(usr->birthdate);
    //result += ";" + usr->;
    return (result);
}
