
#include <cstdlib> // exit_success && exit_failure
#include <iostream>
#include "Application.hh"

#include "data/Acronyms.hh"

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
    // Acronyms acr;
    // AcronymsInit(&acr);
    // acr.activate(&acr, (e_acronyms)4);
    // acr.activate(&acr, (e_acronyms)5);
    // acr.activate(&acr, (e_acronyms)1);
    // acr.activate(&acr, (e_acronyms)0);
    // for (int i = 0; i < 12; i++)
    // {
    //     std::cout << "[" << i << "] " << acr.names[i] << " = ";
    //     std::cout << (acr.selected[i] ? "(true)" : "(false)") << std::endl;
    // }
    // std::cout << acr.ToString(&acr) << std::endl;
    // std::cout << acr.CSVFormatter(&acr) << std::endl;
    // std::cout << acr.CountSelected(&acr) << std::endl;
    // std::cout << acr << std::endl;

    Application app;

    //todo();

    AppInit(&app); /** initialisation of the `app` structure and reading data from file*/
    app.Start(&app); /** start of the inifinite loop in the function `loop` */
    app.Loop(&app); /** execution of the infinite loop */

    AppDestroy(&app); /** cleaning of the structure and saving data */
    return (EXIT_SUCCESS);
}
