
#pragma once

#include <string>
#include <cstddef>
#include "Application.hh"
#include "data/User.hh"

namespace my_string
{
    std::string     *split(const std::string &, char);
    size_t          countDelimiter(const std::string &, char);
    bool            isNumber(const std::string &);
}

namespace io
{
    bool        save_data(const std::string &, User **, size_t);
    std::string *read_data(const std::string &);
    size_t      count_lines(const std::string &);
}
