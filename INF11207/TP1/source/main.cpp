
#include <cstdlib> // exit_success && exit_failure
#include <iostream>
#include "Application.hh"

void todo()
{
    std::cout << "*** reorganize data after an item is removed" << std::endl;
    std::cout << "**** acronyms" << std::endl;
    std::cout << "* termcaps ?? (edit + remove)" << std::endl;
}

int     main() /** no params because they're not used */
{
    Application app;

    todo();

    AppInit(&app); /** initialisation of the `app` structure and reading data from file*/
    app.Start(&app); /** start of the inifinite loop in the function `loop` */
    app.Loop(&app); /** execution of the infinite loop */

    AppDestroy(&app); /** cleaning of the structure and saving data */
    return (EXIT_SUCCESS);
}
