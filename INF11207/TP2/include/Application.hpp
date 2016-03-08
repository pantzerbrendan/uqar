
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <string>
#include "Commands.hpp"

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
    ERROR
} Command;

class Application
{
private:
    bool        _running;
    std::string _prompt;
    std::string _input;

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
