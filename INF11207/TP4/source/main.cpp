#include "Dict.hpp"
#include "MotLePlusLong.hpp"

void            flush(std::string word, std::string prefix, int length, Dict &dict) {
    std::string tmp;

    if (length == 0) {
        if (dict.findWord(prefix))
            std::cout << "Mot de " << prefix.length()
            << " lettre(s) trouvé: "<< prefix << std::endl;
    } else {
        for (size_t i = 0; i < word.length(); i++) {
            if (word.find(word[i], 0) == i) {
                tmp = word;
                flush(tmp.erase(i, 1), prefix + word[i], length - 1, dict);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 2)
        return -1;

    Dict            dict(argv[1]);
    MotLePlusLong   jeux(&dict);
    jeux.resolve();
    return 0;
}
