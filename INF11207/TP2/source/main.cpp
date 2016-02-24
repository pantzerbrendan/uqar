
#include <iostream>

#include <stdlib.h>

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

// mettre ailleurs
static std::string  getCurrentTime()
{
    time_t  now = time(0);
    struct tm   tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
//

int main(int ac, char **av, char **env)
{
    #ifdef DEBUG
    std::clog << getCurrentTime() << " [" << __FUNCTION__ << " (" << __FILE__ << ")] start" << std::endl;
    #endif

    (void)ac;
    (void)av;
    (void)env;

    return (EXIT_SUCCESS);
}
