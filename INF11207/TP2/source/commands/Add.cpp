
#include <string>
#include <iostream>
#include "Commands.hpp"

#include "users/User.hpp"

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

void        add(Application *app)
{
    bool    mode = getMode();
    if (mode) // ajout d'un utilisateur
    {
        std::string firstname = prompt("Prenom : ");
        std::string lastname = prompt("Nom : ");
        std::string birthdate = prompt("Date de naissance [YYYY-MM-DD]: ");

        //User user = new User(firstname, lastname, new Date(birthdate));
    }
    else
    {

    }
}
