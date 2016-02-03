
#include <termios.h>
#include <term.h>
#include <cstdlib>
#include "Termcaps.hh"

termcaps::t_termios     *termcaps::init()
{
    termcaps::t_termios *term = new termcaps::t_termios();
    if (!(term->type = getenv("TERM")) || tgetent(NULL, term->type) <= 0)
    {
        delete term;
        return (NULL);
    }
    return (term);
}
