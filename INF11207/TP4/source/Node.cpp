#include "Node.hpp"

Node::Node(const std::string word, int pos) {
    _bro = NULL;
    if (pos < word.length()) {
        _c = word[pos];
        _son = new Node(word, pos + 1);
    } else {
        _c = '\0';
        _son = NULL;
    }
}

Node::~Node() {
    if (_son != NULL)
        delete(_son);
    if (_bro != NULL)
        delete(_bro);
}

/**
 ** Info: Ajoute un mot à l'arbre lexicographique.
 ** Param: Le mot à ajouter à partir de la position pos.
 ** Return: void.
**/
void                Node::addWord(const std::string word, int pos) {
    if (pos < word.length()) {
        if (_c == word[pos]) {
            if (_son == NULL)
                return;
            _son->addWord(word, pos + 1);
        } else {
            if (_bro == NULL)
                _bro = new Node(word, pos);
            else
                _bro->addWord(word, pos);
        }
    } else {
        if (_c != '\0') {
            if (_bro == NULL)
                _bro = new Node(word, pos);
            else
                _bro->addWord(word, pos);
        }
    }
}

/**
 ** Info: Cherche si un mot existe.
 ** Param: Le mot à rechercher à partir de la position pos.
 ** Return: true si le mot a été trouvé false sinon.
**/
bool                Node::searchWord(const std::string word, int pos) const {
    if (pos < word.length()) {
        if (_c == word[pos])
            return (_son->searchWord(word, pos + 1));
        else {
            if (_bro == NULL)
                return (false);
            else
                return (_bro->searchWord(word, pos));
        }
    } else {
        if (_c == '\0')
            return (true);
        return (false);
    }
}
