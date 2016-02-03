
#pragma once

#include <string>
#include <ostream>

typedef struct s_address
{
    std::string number;
    std::string street;
    std::string city;
    std::string country;

    std::string (*CSVFormatter)(const struct s_address *);
}               Address;

Address         *NewAddress(const std::string &, const std::string &, const std::string &, const std::string &);
void            DeleteAddress(Address *);

std::ostream    &operator<<(std::ostream &, const Address &);
