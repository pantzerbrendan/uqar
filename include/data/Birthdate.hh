
#pragma once

#include <string>
#include <ostream>

typedef struct s_birthdate
{
    int         day;
    int         month;
    int         year;

    std::string (*CSVFormatter)(const struct s_birthdate *);
    std::string (*ToString)(const struct s_birthdate *);
    bool        (*isValid)(const struct s_birthdate *);
}               Birthdate;

Birthdate       *NewBirthdate(const std::string &);
void            DeleteBirthdate(Birthdate *);

std::ostream    &operator<<(std::ostream &, const Birthdate &);
