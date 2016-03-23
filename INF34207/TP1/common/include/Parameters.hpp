
#ifndef PARAMETERS_HPP_
#define PARAMETERS_HPP_

#include <list>
#include <string>
// #include "Environment.hpp" // ./

typedef std::list<std::string>  s_list;

class Parameters
{
private:
    int             _argcount;
    s_list          _argvalues;
    // Environment     *_env;

public:
    Parameters(int, char **, char **);
    ~Parameters();

    // Environment     *getEnvironment() const;
};

#endif /* !PARAMETERS_HPP_ */
