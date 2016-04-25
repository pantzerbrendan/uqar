#include "Dict.hpp"

Dict::Dict(const char *path) {
    std::ifstream   file(path);
    std::string     line;

    _dict = NULL;
    if (file.good()) {
        while (getline(file, line)) {
            if (_dict == NULL)
                _dict = new Node(line, 0);
            else
                _dict->addWord(line, 0);
        }
    } else {
        std::cerr << "ERROR: Impossible de lire le dictionnaire" << std::endl;
    }
}

Dict::~Dict() {
    delete(_dict);
}

/**
 ** Info: Recherche dans l'arbre lexicographique si le mot existe.
 ** Param: Le mot à chercher.
 ** Return: true si le mot est trouvé false sinon.
**/
bool                Dict::findWord(const std::string word) const {
    return (_dict->searchWord(word, 0));
}
