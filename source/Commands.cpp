
#include <string>
#include <iostream>
#include <sstream>
#include "Application.hh"
#include "Commands.hh"
#include "utils/utils.hh"

/* STATIC FUNCTION PROTOTYPES */
static void addUser(Application *);
static void editUser(Application *);
static void removeUser(Application *);
static void listData(Application *);
static void saveData(Application *);
static void exitApp(Application *);
static void help(Application *);
static void errorCMD(Application *);
/* !STATIC FUNCTION PROTOTYPES */

/*
** Displays the first parameter as a prompt. This function is only used when the
** user wants to add or edit an user of the data structure. The last parameter
** represents the current value of the edited user data. This parameter takes a
** default value (an empty string) only when this function is called within the
** addition command.
** If this function is called within the addition command, and the user didn't
** enter any character when prompted, re-loops on it until he has entered at least
** one character.
** If it is called within the edition command, and the user didn't enter any
** character, returns the default value passed as parameter.
*/
static std::string  edition_prompt(const std::string &text, const std::string value = "")
{
    std::string input = "";
    while (input == "")
    {
        std::cout << "\033[36m" << text;
        if (value != "")
        std::cout << "[" << value << "]";
        std::cout << " :\033[0m ";

        getline(std::cin, input);

        if (input == "" && value != "") return (value);
    }
    return (input);
}

/*
**
*/
static int          id_selector(const std::string &text)
{
    bool valid = false;
    int id;
    while (!valid)
    {
        std::string response = "";
        std::cout << text;
        getline(std::cin, response);
        std::istringstream(response) >> id;
        if (id >= 0 && id < 30) valid = true;
    }
    return (id);
}

/*
** Initializes the function pointer array used to call the different functions
** of the application.
*/
void        CommandInit(Application *app)
{
    app->commands[ADD] = &addUser;
    app->commands[EDIT] = &editUser;
    app->commands[DELETE] = &removeUser;
    app->commands[LIST] = &listData;
    app->commands[SAVE] = &saveData;
    app->commands[EXIT] = &exitApp;
    app->commands[HELP] = &help;
    app->commands[ERROR] = &errorCMD;
}

/*
**
*/
e_cmd       getCommand(const std::string &cmd)
{
    if (cmd == "add")           return (ADD);
    else if (cmd == "edit")     return (EDIT);
    else if (cmd == "remove" || cmd == "delete") return (DELETE);
    else if (cmd == "list")     return (LIST);
    else if (cmd == "save")     return (SAVE);
    else if (cmd == "exit")     return (EXIT);
    else if (cmd == "help")     return (HELP);

    return (ERROR);
}

/* Static functions definition */

/*
** Prompts the user to enter the data used to create a new user in the database.
** Creates then corresponding structure instances and adds the user to the database
** within the Application structure instance.
*/
static void addUser(Application *app)
{
    std::cout << "-> Ajouter un utilisateur..." << std::endl;

    std::string firstname = edition_prompt("Prénom");
    std::string lastname = edition_prompt("Nom");
    std::string birthdate = edition_prompt("Date de naissance (jj/mm/aaaa)");
    std::cout << "\033[36mAdresse\033[0m" << std::endl;
    std::string number = edition_prompt("\tNuméro");
    std::string street = edition_prompt("\tRue");
    std::string city = edition_prompt("\tVille");
    std::string country = edition_prompt("\tPays");

    Birthdate *birth = NewBirthdate(birthdate);
    Address *address = NewAddress(number, street, city, country);
    if (birth && address)
    {
        User *user = NewUser(firstname, lastname, address, birth);
        if (app->Add(app, user))
        {
            std::clog << "L'utilisateur [" << firstname << ' ' << lastname << "] a correctement été ajouté." << std::endl;
            return ;
        }
        DeleteUser(user);
    }
    DeleteAddress(address);
    DeleteBirthdate(birth);
    std::cerr << "Impossible d'ajouter l'utilisateur..." << std::endl;
}

/*
**
*/
static void editUser(Application *app)
{
    // termcaps ?
    // select User
    int id = -1;
    while (id == -1)
    {
        id = id_selector("Entrez l'id de l'utilisateur à supprimer : ");
        if (app->data[id] == NULL)
            id = -1;
    }

    std::string firstname = edition_prompt("Prénom", app->data[id]->firstname);
    std::string lastname = edition_prompt("Nom", app->data[id]->lastname);
    std::string birthdate = edition_prompt("Date de naissance (jj/mm/aaaa)", app->data[id]->birthdate->ToString(app->data[id]->birthdate));
    std::cout << "\033[36mAdresse\033[0m" << std::endl;
    std::string number = edition_prompt("\tNuméro", app->data[id]->address->number);
    std::string street = edition_prompt("\tRue", app->data[id]->address->street);
    std::string city = edition_prompt("\tVille", app->data[id]->address->city);
    std::string country = edition_prompt("\tPays", app->data[id]->address->country);

    Birthdate *birth = NewBirthdate(birthdate);
    Address *address = NewAddress(number, street, city, country);
    if (birth && address)
    {
        User *user = NewUser(firstname, lastname, address, birth);
        if (app->Edit(app, (size_t)id, user))
        {
            std::clog << "L'utilisateur [" << firstname << ' ' << lastname << "] a correctement été modifié." << std::endl;
            return ;
        }
        DeleteUser(user);
    }
    DeleteAddress(address);
    DeleteBirthdate(birth);
    std::cerr << "Impossible de modifier l'utilisateur..." << std::endl;
}

/*
**
*/
static void removeUser(Application *app)
{
    int id = id_selector("Entrez l'id de l'utilisateur à supprimer : ");
    if (!(app->Remove(app, (size_t)id)))
        std::cerr << "Impossible de supprimer l'utilisateur" << std::endl;
    else
        std::clog << "L'utilisateur ayant l'id [" << id << "] a été supprimé" << std::endl;
}

/*
**
*/
static void listData(Application *app)
{
    size_t index = 0;
    for (; app->data[index]; index++)
        std::cout << "[" << index << "] " << *(app->data[index]) << std::endl;
    std::clog << "Eléments présents dans la base de données : " << index << std::endl;
}

/*
**
*/
static void saveData(Application *app)
{
    if (io::save_data(app->save_file, app->data, app->CountUsers(app)))
        std::clog << "Données sauvegardées avec succès" << std::endl;
    else
        std::cerr << "Erreur lors de la sauvegarde" << std::endl;
}

/*
**
*/
static void exitApp(Application *app)
{
    app->Stop(app);
}

/*
**
*/
static void help(Application *app)
{
    std::cout << "\033[34m=== AIDE ===\033[0m" << std::endl << std::endl;
    std::cout << "Plusieurs commandes sont à votre disposition :"<< std::endl;
    std::cout << "\t`- add : permet d'ajouter un nouvel utilisateur." << std::endl;
    std::cout << "\t`- edit : permet de modifier un utilisateur." << std::endl;
    std::cout << "\t`- delete : permet de supprimer un utilisateur. (remove fonctionne également)" << std::endl;
    std::cout << "\t`- list : permet d'afficher sous forme de liste tous les utilisateurs." << std::endl;
    std::cout << "\t`- save : sauvegarde tous les changement faits aux données dans le fichier `" << app->save_file << "`" << std::endl;
    std::cout << "\t`- exit : permet de quitter l'application." << std::endl;
    std::cout << "\t`- help : affiche l'aide." << std::endl << std::endl;
    std::cout << "Aucune commande ne prend de paramètres." << std::endl;
}

/*
**
*/
static void errorCMD(Application *app)
{
    std::cerr << "\033[31m" << "Erreur : `";
    std::cerr << app->lastCommand << "` commande non trouvée..." << std::endl;
    std::cerr << "Tapez la commande `help` pour plus d'informations" << "\033[0m" << std::endl;
}
