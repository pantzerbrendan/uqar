
#ifndef DATE_HPP_
#define DATE_HPP_

#include <ctime>
#include <string>
#include <stdio.h>

#define BUF_LEN 32

class Date {
private:
    struct tm   date;
public:
    Date ();                        //Set date at the current time
    Date (const std::string date);  //Set date at the date value (YYYY-MM-DD)
    ~Date ();

    std::string     getDate() const;
};

#endif /* !DATE_HPP_ */
