
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <string>
#include <map>
#include "Commands.hpp"

class Application;
typedef void (*fct_ptr)(Application *);

typedef enum {
    EXIT,
    HELP,
    LIST,
    ADD,
    EDIT,
    REMOVE,
    WITHDRAW,
    DEPOSIT,
    CLEAR,
    ERROR,
    CMD_NBR
} Command;

class Application
{
private:
    bool        _running;
    std::string _prompt;
    std::string _input;

    fct_ptr     _commands[CMD_NBR];

public:
    Application();
    virtual ~Application();

    void        start();
    void        loop();
    void        stop();
    void        help();

private:
    void        execute();
};

#endif /* !APPLICATION_HPP_ */
