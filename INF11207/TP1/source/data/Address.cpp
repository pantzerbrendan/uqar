
#include <string>
#include <ostream>
#include "data/Address.hh"

static std::string      A_CSVFormatter(const Address *);

Address         *NewAddress(const std::string &number, const std::string &street, const std::string &city, const std::string &country)
{
    Address     *addr = new Address();

    addr->number = number;
    addr->street = street;
    addr->city = city;
    addr->country = country;

    /** function pointer initialization */
    addr->CSVFormatter = &A_CSVFormatter;
    return (addr);
}

void            DeleteAddress(Address *addr)
{
    if (!addr) return ;
    delete addr;
    addr = NULL;
}

std::ostream    &operator<<(std::ostream &stream, const Address &addr)
{
    stream << addr.number << " ";
    stream << addr.street << " ";
    stream << addr.city << " - ";
    stream << addr.country;
    return (stream);
}

static std::string  A_CSVFormatter(const Address *addr) { return (addr->number + ";" + addr->street + ";" + addr->city + ";" + addr->country); }
