#ifndef NODE_HPP
#define NODE_HPP

#include <string>

/**
 ** Cette classe représente un noeud dans la constitution
 ** d'une arbre lexicographique.
**/
class           Node {
private:
    Node*       _son;
    Node*       _bro;
    char        _c;

public:
    Node (const std::string word, int pos);
    virtual ~Node ();

    //Ajoute un mot à l'arbre lexicographique.
    void        addWord(const std::string word, int pos);
    //Cherche si un mot existe.
    bool        searchWord(const std::string word, int pos) const;
};

#endif
