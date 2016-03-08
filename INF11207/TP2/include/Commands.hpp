
#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_

#include "Application.hpp"

class Application;

void    list_accounts(Application *);
void    add(Application *);
void    edit(Application *);
void    deposit(Application *);
void    withdraw(Application *);
void    save(Application *);

#endif /* !COMMANDS_HPP_ */
