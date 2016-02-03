
#pragma once

#include <termios.h>
#include <term.h>
#include <unistd.h>

// nnot used ??
namespace termcaps
{
    typedef struct      s_termios
    {
        char            *type;
        struct termios  term;
    }                   t_termios;

    termcaps::t_termios *init();
    void                clearScreen(t_termios *);
}
