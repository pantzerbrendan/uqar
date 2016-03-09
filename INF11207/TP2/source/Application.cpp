
#include <iostream>
#include "Application.hpp"

Command     getCommand(const std::string &param)
{
    if (param == "exit") return (EXIT);
    else if (param == "help") return (HELP);
    else if (param == "list") return (LIST);
    else if (param == "add") return (ADD);
    else if (param == "edit") return (EDIT);
    else if (param == "deposit") return (DEPOSIT);
    else if (param == "withdraw") return (WITHDRAW);
    else if (param == "clear") return (CLEAR);
    else if (param == "remove") return (REMOVE);
    else if (param == "deposit") return (DEPOSIT);
    return (ERROR);
}

Application::Application() : _running(false)
{
    this->_prompt = "$> ";
    this->_bank = new Bank();

    this->_commands[EXIT] = &Commands::quit;
    this->_commands[HELP] = &Commands::help;
    this->_commands[LIST] = &Commands::list_accounts;
    this->_commands[ADD] = &Commands::add;
    this->_commands[EDIT] = &Commands::edit;
    this->_commands[REMOVE] = &Commands::remove;
    this->_commands[WITHDRAW] = &Commands::withdraw;
    this->_commands[DEPOSIT] = &Commands::deposit;
    this->_commands[CLEAR] = &Commands::clear;
    this->_commands[ERROR] = &Commands::error;
}

Application::~Application() {}

void    Application::start() { this->_running = true; }
void    Application::stop() { this->_running = false; }

void    Application::loop()
{
    while (this->_running)
    {
        std::cout << this->_prompt;
        getline(std::cin, this->_input);
        this->_commands[getCommand(this->_input)](this);
    }
}

void    Application::help()
{
    std::cout << "Liste des commandes :" << std::endl;
    std::cout << "  - list" << std::endl;
    std::cout << "  - add" << std::endl;
    std::cout << "  - edit" << std::endl;
    std::cout << "  - deposit" << std::endl;
    std::cout << "  - withdraw" << std::endl;
    std::cout << "  - exit" << std::endl;
    std::cout << "  - help" << std::endl;
}
