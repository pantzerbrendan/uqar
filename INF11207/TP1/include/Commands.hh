
#pragma once

#include <string>
#include "Application.hh"

typedef struct  s_application    Application;
enum e_cmd { ADD, EDIT, DELETE, LIST, SAVE, EXIT, HELP, ERROR, CLEAR, NB_CMD };

void        CommandInit(Application *);
e_cmd       getCommand(const std::string &);
