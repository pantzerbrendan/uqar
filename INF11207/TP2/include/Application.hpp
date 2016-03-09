
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <string>
#include <map>
#include "Commands.hpp"
#include "data/Bank.hpp"

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
    Bank        *_bank;

    fct_ptr     _commands[CMD_NBR];

public:
    Application();
    virtual ~Application();

    void        start();
    void        loop();
    void        stop();
    void        help();
};

#endif /* !APPLICATION_HPP_ */
