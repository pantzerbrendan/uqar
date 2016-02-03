
#pragma once

#include <string>
#include <cstddef>
#include "data/User.hh"

typedef struct  s_application    Application;
typedef void (*fct_ptr)(Application *);

typedef struct  s_application
{
    /* default data for the structure */
    std::string     prompt;
    std::string     save_file;
    bool            running;
    std::string     lastCommand;

    /* function pointers array for the different commands */
    fct_ptr         commands[8];

    /* data : contains data in the database */
    User            *data[30];

    /* function pointers */
    void            (*Start)(struct s_application *);
    void            (*Stop)(struct s_application *);
    void            (*Loop)(struct s_application *);
    size_t          (*CountUsers)(struct s_application *);
    bool            (*Add)(struct s_application *, User *);
    bool            (*Remove)(struct s_application *, size_t);
    bool            (*Edit)(struct s_application *, size_t, User *);
}               Application;

void        AppInit(Application *);
void        AppDestroy(Application *);
