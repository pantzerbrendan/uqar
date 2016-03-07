
#include <iostream>

#include <stdlib.h>

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

#include "factory/Factory.hpp"
#include "Accounts/RetirementAccount.hh"

// mettre ailleurs
static std::string  getCurrentTime()
{
    time_t  now = time(0);
    struct tm   tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
//

void testAccount() {
    RetirementAccount *account = new RetirementAccount(NULL, 1);
    account->deposit(1000.2);
    try {
        account->withdrawal(10);
    } catch(const std::string &e) {
        std::cout << "ERROR: " << e << std::endl;
    }
    try {
        account->setAuth(true);
        account->withdrawal(500.2);
        std::cout << "Balance = " << account->getBalance() << std::endl;
        account->withdrawal(800);
        std::cout << "Balance = " << account->getBalance() << std::endl;
    } catch(std::string const &e) {
        std::cout << "ERROR: " << e << std::endl;
    }
    delete(account);
}

int main(int ac, char **av, char **env)
{
    #ifdef DEBUG
    std::clog << getCurrentTime() << " [" << __FUNCTION__ << " (" << __FILE__ << ")] start" << std::endl;
    #endif

    // testAccount();

    (void)ac;
    (void)av;
    (void)env;

    return (EXIT_SUCCESS);
}
