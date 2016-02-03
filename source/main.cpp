
#include <cstdlib> // exit_success && exit_failure
#include <iostream>
#include "Application.hh"

void todo()
{
    std::cout << "1** edit" << std::endl;
    std::cout << "2** remove" << std::endl;
    std::cout << "3* reorganize data after an item is removed" << std::endl;
    std::cout << "4*** read data from file" << std::endl;
    std::cout << std::endl << "1+2 : termcaps ??" << std::endl;
}

int     main() /** no params because they're not used */
{
    Application app;

    //todo();

    AppInit(&app); /** initialisation of the `app` structure and reading data from file*/
    app.Start(&app); /** start of the inifinite loop in the function `loop` */
    app.Loop(&app); /** execution of the infinite loop */

    AppDestroy(&app); /** cleaning of the structure and saving data */
    return (EXIT_SUCCESS);
}
