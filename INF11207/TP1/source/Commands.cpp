
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
static void clear(Application *);
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
** Function used to loop while the id entered by the user is not in (0:29) or is
** is not a number.
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


static bool     boolean_prompt(const std::string &text)
{
    std::string input;
    while (input[0] != 'Y' && input[0] != 'y' && input[0] != 'N' && input[0] != 'n')
    {
        std::cout << text << " [Y/n] ";
        getline(std::cin, input);
    }
    return (input == "Y" || input == "y");
}

static void     acronym_editor(Acronyms *acronyms)
{
    for (int i = 0; i < NB_ACRONYMS; i++)
    {
        bool result = boolean_prompt(acronyms->names[i]);
        if (result)
        {
            if (!acronyms->activate(acronyms, (e_acronyms)i))
            {
                std::cerr << "Impossible de sélectionner plus de cours" << std::endl;
                break ;
            }
        }
        else
            acronyms->deactivate(acronyms, (e_acronyms)i);
    }
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
    app->commands[CLEAR] = &clear;
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
    else if (cmd == "clear")    return (CLEAR);

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
        Acronyms *acronyms = new Acronyms();
        AcronymsInit(acronyms);
        acronym_editor(acronyms);

        User *user = NewUser(firstname, lastname, address, birth, acronyms);
        if (app->Add(app, user))
        {
            std::clog << "L'utilisateur [" << firstname << ' ' << lastname << "] a correctement été ajouté." << std::endl;
            return ;
        }
        AcronymsDestroy(acronyms);
        DeleteUser(user);
    }
    DeleteAddress(address);
    DeleteBirthdate(birth);
    std::cerr << "Impossible d'ajouter l'utilisateur..." << std::endl;
}

/*
** Prompts the user to enter the `id` of the user he wants to edit, then asks him
** for the informations such as the firstname, lastname, ... and the creates the
** corresponding objects and tries to change the data using the `Edit` function pointer.
** If data is successfully changed, displays a `success` message, and displays a `failure`
** message otherwise.
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
        Acronyms *acronyms = new Acronyms();
        AcronymsInit(acronyms);
        acronym_editor(acronyms);

        User *user = NewUser(firstname, lastname, address, birth, acronyms);
        if (app->Edit(app, (size_t)id, user))
        {
            std::clog << "L'utilisateur [" << firstname << ' ' << lastname << "] a correctement été modifié." << std::endl;
            return ;
        }
        AcronymsDestroy(acronyms);
        DeleteUser(user);
    }
    DeleteAddress(address);
    DeleteBirthdate(birth);
    std::cerr << "Impossible de modifier l'utilisateur..." << std::endl;
}

/*
** Prompts the user to enter the `id` of the user he wants to remove. If a user
** with the corresponding id exists, this user will be removed and a `success`
** message will be displayed, if not, no changes will be made to the database and
** a `failure` message will be displayed.
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
** Lists all data contained in the database according this format :
**  firstname lastname, number street city - country, birthdate, acronyms
*/
static void listData(Application *app)
{
    size_t index = 0;
    for (; app->data[index]; index++)
        std::cout << "[" << index << "] " << *(app->data[index]) << std::endl;
    std::clog << "Eléments présents dans la base de données : " << index << std::endl;
}

/*
** Saves all data contained in the database in the `./data.csv` file. If data is
** successfully saved, displays a `success` message, and displays a `failure` message
** otherwise.
*/
static void saveData(Application *app)
{
    if (io::save_data(app->save_file, app->data, app->CountUsers(app)))
        std::clog << "Données sauvegardées avec succès" << std::endl;
    else
        std::cerr << "Erreur lors de la sauvegarde" << std::endl;
}

/*
** Stops the application so it can exit correctly by freeing all data.
*/
static void exitApp(Application *app)
{
    app->Stop(app);
}

/*
** Displays a 'simple' help message, containing all commands and their function.
*/
static void help(Application *app)
{
    std::cout << "\033[34m=== AIDE ===\033[0m" << std::endl << std::endl;
    std::cout << "Plusieurs commandes sont à votre disposition :"<< std::endl;
    std::cout << "\t`- add : permet d'ajouter un nouvel utilisateur." << std::endl;
    std::cout << "\t`- edit : permet de modifier un utilisateur." << std::endl;
    std::cout << "\t`- delete : permet de supprimer un utilisateur. (remove fonctionne également)" << std::endl;
    std::cout << "\t`- list : permet d'afficher sous forme de liste tous les utilisateurs." << std::endl;
    std::cout << "\t`- save : sauvegarde tous les changements faits aux données dans le fichier `" << app->save_file << "`" << std::endl;
    std::cout << "\t`- clear : efface l'écran" << std::endl;
    std::cout << "\t`- exit : permet de quitter l'application." << std::endl;
    std::cout << "\t`- help : affiche l'aide." << std::endl << std::endl;
    std::cout << "Aucune commande ne prend de paramètres." << std::endl;
}

/*
** Clears the screen.
*/
static void clear(Application *app)
{
    std::cout << "\e[1;1H\e[2J"; /** maybe use termcaps instead */
    (void)app;
}

/*
** Displays an error message if the command entered by the user is not recognized.
*/
static void errorCMD(Application *app)
{
    std::cerr << "\033[31m" << "Erreur : `";
    std::cerr << app->lastCommand << "` commande non trouvée..." << std::endl;
    std::cerr << "Tapez la commande `help` pour plus d'informations" << "\033[0m" << std::endl;
}
