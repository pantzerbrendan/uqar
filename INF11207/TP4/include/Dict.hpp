#ifndef DICT_HPP
#define DICT_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "Node.hpp"

/**
 ** Cette classe constitue un arbre lexicographique
 ** à partir d'un fichier passé au constructeur.
**/
class               Dict {
private:
    Node*           _dict;

public:
    Dict (const char *path);
    virtual ~Dict ();

    //Recherche dans l'arbre lexicographique si le mot existe.
    bool            findWord(const std::string word) const;
};

#endif
