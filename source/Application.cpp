
#include <iostream>
#include "Application.hh"
#include "Commands.hh"
#include "data/User.hh"
#include "utils/utils.hh"

/* STATIC PROTOTYPES */
static void     start(Application *);
static void     stop(Application *);
static void     loop(Application *);
static size_t   countUsers(Application *);
static bool     add(Application *app, User *data);
static bool     remove(Application *app, size_t index);
static bool     edit(Application *app, size_t index, User *data);
/* !STATIC PROTOTYPES */

/*
** Initializes a new Application structure instance with corresponding data.
** Values for save_file, running and prompt are the default ones when
** initialized. Commands are initialized seperately in the `commandInit`
** function. Then function pointers are initialized to ease the use of the
** program structure.
*/
void        AppInit(Application *app)
{
    app->prompt = "\033[32m$> \033[0m";
    app->running = false;
    app->save_file = "./data.csv";

    // "bzero" data array
    for (size_t index = 0; index < 30; index++)
        app->data[index] = NULL;

    // read file and initialize data
    std::string *array = io::read_data(app->save_file);
    size_t nb_lines = io::count_lines(app->save_file);
    for (size_t index = 0; index < nb_lines; index++)
       app->data[index] = NewUser(array[index]);

    // initializes commands function pointers array
    CommandInit(app);

    app->Start = &start;
    app->Stop = &stop;
    app->Loop = &loop;
    app->CountUsers = &countUsers;

    app->Add = &add;
    app->Remove = &remove;
    app->Edit = &edit;
}

/*
** Destroys the Application structure instance. Clears and deletes all pointers.
** Prompts the user if he wants to save data in the file or not. If the user wants to
** save data, calls the corresponding function through the function pointer `save`.
** Then deletes data and quits the program right after the end of this function.
*/
void        AppDestroy(Application *app)
{
    std::string response = "";
    while (response[0] != 'Y' && response[0] != 'y' && response[0] != 'N' && response[0] != 'n')
    {
        std::cout << "\033[35mSouhaitez-vous sauvegarder les données dans le fichier `" << app->save_file << "` ? [Y/n]\033[0m ";
        getline(std::cin, response);
    }
    if (response[0] == 'Y' || response[0] == 'y')
        app->commands[SAVE](app);
    for (size_t index = 0; app->data[index]; index++)
        DeleteUser(app->data[index]);
}

/* STATIC FUNCTIONS */

static void start(Application *app) { app->running = true; }
static void stop(Application *app) { app->running = false; }

/*
** Function representing an infinite loop depending on the value of `running`. If
** running is `true`, executes the code inside the loop, otherwise ends this function.
** Each tine, displays the prompt defined in the Application structure instance, then
** reads the input and stores it in a string of the Application structure instance.
** Uses then a function pointer array to execute the function corresponding to the input.
*/
static void loop(Application *app)
{
    while (app->running)
    {
        std::cout << app->prompt; /** display prompt */
        getline(std::cin, app->lastCommand); /** read user input */
        app->commands[getCommand(app->lastCommand)](app); /** execute the command corresponding to the input */
    }
}

/*
**
*/
static size_t countUsers(Application *app)
{
    size_t count = 0;
    for (; app->data[count]; count++);
    return (count);
}

/*
**
*/
static bool add(Application *app, User *toAdd)
{
    size_t index = app->CountUsers(app); /** gets the index of the last object */
    if (index >= 30)
    {
        std::cerr << "Impossible d'ajouter un nouvel utilisateur..." << std::endl;
        return (false);
    }
    if (!toAdd || !app) return (false); /** Could not add data to the database */
    app->data[index] = toAdd; /** insert data at the specified index */
    return (true); /** data correctly added to the database */
}

/*
**
*/
static bool remove(Application *app, size_t index)
{
    if (index >= 30) return (false); /** could not remove data : out of bounds */
    if (!app || !(app->data[index])) return (false); /** could not remove data : inexistant */
    DeleteUser(app->data[index]);
    app->data[index] = NULL;
    return (true); /** data successfully removed */
}

/*
**
*/
static bool edit(Application *app, size_t index, User *data)
{
    if (index >= 30) return (false); /** could not remove data : out of bounds */
    if (!app || !data) return (false); /** could not change data : null */
    app->data[index] = data;
    return (true); /** data successfully changed */
}

/* !STATIC FUNCTIONS */
