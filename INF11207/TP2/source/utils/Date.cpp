#include "utils/Date.hpp"

#include <iostream>

Date::Date() {
    time_t      tmp;

    time(&tmp);
    this->date = *gmtime(&tmp);
}

Date::Date(const std::string date) {
    if (strptime(date.c_str(), "%F", &this->date) == NULL)
        throw std::string("Invalid format, need to be YYYY-MM-DD");
}

Date::~Date() {

}

std::string     Date::getDate() const {
    std::string res;
    char        buff[BUF_LEN];

    if (strftime(&buff[0], BUF_LEN, "%F", &this->date) == 0)
        res = "";
    else
        res.assign(buff);
    return (res);
}
