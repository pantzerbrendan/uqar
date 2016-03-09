
#include <iostream>
#include "factory/AccountFactory.hpp"
#include "Commands.hpp"

static std::string prompt(const std::string &text)
{
    std::string input = "";
    while (input == "")
    {
        std::cout << text;
        getline(std::cin, input);
    }
    return (input);
}

static bool     getMode()
{
    std::string input = "";
    while (input[0] != '1' && input[0] != '2')
    {
        std::cout << "Ajouter un utilisateur(1) ou un compte(2) ? [1/2] : ";
        getline(std::cin, input);
    }
    return (input == "1");
}

static AccountEnum getAccountType(const std::string &str)
{
    if (str == "Epargne") return REGULAR;
    else if (str == "Retraite") return RETIREMENT;
}

void    Commands::list_accounts(Application *app)
{

}

void    Commands::add(Application *)
{
    bool    mode = getMode();
    if (mode) // ajout d'un utilisateur
    {
        std::string firstname = prompt("Prenom : ");
        std::string lastname = prompt("Nom : ");
        Date *birthdate = new Date(prompt("Date de naissance [YYYY-MM-DD]: "));

        //User user = new User(firstname, lastname, new Date(birthdate));
    }
    else
    {
        std::string owner_name = prompt("Nom du proprietaire : ");
        Date *birthdate = new Date(prompt("Date de naissance du proprietaire [YYYY-MM-DD]: "));

        // check age
        AccountEnum type = getAccountType(prompt("Type du compte [Epargne / Retraite] : "));
        std::string str;
        //A_Account *account = Factories::Factory::newObject(, str);
    }
}

void    Commands::edit(Application *)
{

}

void    Commands::deposit(Application *)
{

}

void    Commands::withdraw(Application *)
{

}

void    Commands::save(Application *)
{

}

void    Commands::error(Application *)
{

}

void    Commands::remove(Application *)
{

}

void    Commands::quit(Application *)
{

}

void    Commands::help(Application *)
{

}

void    Commands::clear(Application *)
{
    
}
