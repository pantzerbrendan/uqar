#include <iostream>
#include <string>
#include <sstream> // for istringstream (convert string to int)
#include "data/Birthdate.hh"
#include "utils/utils.hh"

static std::string  B_CSVFormatter(const Birthdate *);
static std::string  B_ToString(const Birthdate *);
static bool         isValid(const Birthdate *);

Birthdate   *NewBirthdate(const std::string &str)
{
    Birthdate *date = new Birthdate();

    std::string *array = my_string::split(str, '/');
    if (array == NULL || !my_string::isNumber(array[0]) || !my_string::isNumber(array[1]) || !my_string::isNumber(array[2]))
    {
        delete date;
        if (array != NULL) delete[] array;
        return (NULL);
    }
    std::istringstream(array[0]) >> date->day;
    std::istringstream(array[1]) >> date->month;
    std::istringstream(array[2]) >> date->year;
    delete[] array;

    if (!isValid(date))
    {
        delete date;
        return (NULL);
    }
    date->isValid = &isValid;
    date->ToString = &B_ToString;
    date->CSVFormatter = &B_CSVFormatter;
    return (date);
}

void        DeleteBirthdate(Birthdate *date)
{
    if (!date) return ;
    delete date;
    date = NULL;
}

std::ostream    &operator<<(std::ostream &stream, const Birthdate &date)
{
    stream << date.day << "/";
    stream << date.month << "/";
    stream << date.year;

    return (stream);
}

static std::string  B_CSVFormatter(const Birthdate *date) { return (date->ToString(date)); }

static std::string  B_ToString(const Birthdate *date)
{
    std::string str = std::to_string(date->day) + "/";
    str += std::to_string(date->month) + "/";
    str += std::to_string(date->year);
    return (str);
}

static bool         isValid(const Birthdate *date)
{
    // check year
    if (date->year < 0) return (false);
    // check month
    if (date->month <= 0 || date->month > 12) return (false);
    // check days in 31-day months
    if (date->month == 1 || date->month == 3 || date->month == 5 || date->month == 7 || date->month == 8 || date->month == 10 || date->month == 12)
    {
        if (date->day > 31 || date->day <= 0)
            return (false);
    }
    // check days in non 31-day months
    else
    {
        if (date->day > 30 || date->day <= 0) return (false);
    }
    // if everything is correct, returns true
    return (true);
}
