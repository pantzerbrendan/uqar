
#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_

#include "Application.hpp"

class Application;

class Commands {
private:
    Commands();
    virtual ~Commands ();

public:
    static void     list_accounts(Application *);
    static void     add(Application *);
    static void     remove(Application *);
    static void     edit(Application *);
    static void     deposit(Application *);
    static void     withdraw(Application *);
    static void     save(Application *);
    static void     quit(Application *);
    static void     help(Application *);
    static void     error(Application *);
    static void     clear(Application *);

};

#endif /* !COMMANDS_HPP_ */
