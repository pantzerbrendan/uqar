
#include <iostream>
#include "Application.hpp"

Command     getCommand(const std::string &param)
{
    if (param == "exit") return (EXIT);
    else if (param == "help") return (HELP);
    return (ERROR);
}

Application::Application() : _running(false)
{
    this->_prompt = "$> ";
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
        this->execute();
    }
}

void    Application::execute()
{
    Command cmd = getCommand(this->_input);
    switch (cmd)
    {
        case EXIT:
            this->stop();
            break;
        case HELP:
            this->help();
            break;
        case ERROR:
            std::cerr << "Commande invalide" << std::endl;
            break;
        default:
            break;
    }
}

void    Application::help()
{
    std::cout << "Liste des commandes :" << std::endl;
    std::cout << "  - exit" << std::endl;
    std::cout << "  - help" << std::endl;
}
