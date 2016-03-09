
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

static bool     getMode(const std::string &text)
{
    std::string input = "";
    while (input[0] != '1' && input[0] != '2')
    {
        std::cout << text;
        getline(std::cin, input);
    }
    return (input == "1");
}

static AccountEnum getAccountType(const std::string &str)
{
    if (str == "Epargne") return REGULAR;
    else if (str == "Retraite") return RETIREMENT;
}

void    Commands::add(Application *app)
{
    try
    {
        bool    mode = getMode("Ajouter un utilisateur(1) ou un compte(2) ? [1/2] : ");
        if (mode) // ajout d'un utilisateur
        {
            std::string firstname = prompt("Prenom : ");
            std::string lastname = prompt("Nom : ");
            Date *birthdate = new Date(prompt("Date de naissance [YYYY-MM-DD]: "));

            //User user = new User(firstname, lastname, new Date(birthdate));
        }
        else // ajout d'un compte
        {
            std::string owner_name = prompt("Nom du proprietaire : ");
            Date *birthdate = new Date(prompt("Date de naissance du proprietaire [YYYY-MM-DD]: "));

            // check age
            AccountEnum type = getAccountType(prompt("Type du compte [Epargne / Retraite] : "));
            std::string str;
            u_int id = app->maxAID();
            //A_Account *account = Factories::Factory::newObject(, str);
        }
    } catch (std::string str)
    {
        std::cerr << str << std::endl;
    }
}

void    Commands::edit(Application *)
{
    try
    {
        bool    mode = getMode("Modifier un utilisateur(1) ou un compte(2) ? [1/2] : ");
        if (mode) // modification d'un utilisateur
        {

        }
        else // modification d'un compte
        {

        }
    } catch (std::string str)
    {
        std::cerr << str << std::endl;
    }
}

void    Commands::deposit(Application *)
{
    std::clog << "Non implemente" << std::endl;
}

void    Commands::withdraw(Application *)
{
    std::clog << "Non implemente" << std::endl;
}

void    Commands::save(Application *)
{
    std::clog << "Non implemente" << std::endl;
}

void    Commands::error(Application *app)
{
    std::cerr << "\033[31m" << "Erreur : `";
    std::cerr << app->getInput() << "` commande non trouvée..." << std::endl;
    std::cerr << "Tapez la commande `help` pour plus d'informations" << "\033[0m" << std::endl;
}

void    Commands::remove(Application *)
{

}

void    Commands::quit(Application *app)
{
    app->stop();
}

void    Commands::help(Application *app)
{
    std::cout << "Commandes disponibles :" << std::endl;
    std::cout << "\t- add" << std::endl;
    std::cout << "\t- edit" << std::endl;
    std::cout << "\t- remove" << std::endl;
    std::cout << "\t- list" << std::endl;
    std::cout << "\t- deposit" << std::endl;
    std::cout << "\t- withdraw" << std::endl;
    std::cout << "\t- exit" << std::endl;
    std::cout << "\t- clear" << std::endl;
    std::cout << "\t- help" << std::endl;
    (void)app;
}

void    Commands::clear(Application *)
{
    std::cout << "\e[1;1H\e[2J";
}

void    Commands::list_accounts(Application *app)
{
    std::list<A_Account *> accounts = app->getBank()->getAccounts();
    std::list<A_Account *>::const_iterator iterator = accounts.begin();

    std::cout << "ID | PROPRIETAIRE | SOLDE" << std::endl;
    for (; iterator != accounts.end(); iterator++)
    {
        std::cout << (*iterator)->getId() << " | "
            << (*iterator)->getOwner()->getFirstname() << " " << (*iterator)->getOwner()->getLastname() << " | "
            << (*iterator)->getBalance() << std::endl;
    }
}
