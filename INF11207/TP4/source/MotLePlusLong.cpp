#include "MotLePlusLong.hpp"

MotLePlusLong::MotLePlusLong(const Dict *dict) {
    _dict = dict;
    _tests.clear();
    _solution.clear();

    do {
        std::cout << "Entrez la sequence de lettre [a..z]: ";
        std::cin >> _jeux;
//      std::cout << std::endl;
    } while(!testJeux());

}

MotLePlusLong::~MotLePlusLong() {

}

bool            MotLePlusLong::testJeux() {

    if (_jeux.length() < 1) {
        std::cout << "Erreur, jeux de caractère trop court" << std::endl;
        _jeux.clear();
        return (false);
    }

    if (_jeux.length() > 10)
        _jeux.erase(10, std::string::npos);

    for (size_t i = 0; i < _jeux.length(); i++) {
        if (_jeux[i] < 'a' || _jeux[i] > 'z') {
            std::cout << "Erreur, mauvais caractère: "
            << _jeux[i] << std::endl;
            _jeux.clear();
            return (false);
        }
    }
    return (true);
}

void        MotLePlusLong::flush(std::string word, std::string prefix, int length) {
    std::string tmp;

    if (length == 0) {
        if (_dict->findWord(prefix)) {
            _solution = prefix;
            stopTimer();
        }
        _tests.push_front(prefix);
    } else {
        for (size_t i = 0; i < word.length(); i++) {
            if (!_solution.empty())
                return;
            if (word.find(word[i], 0) == i) {
                tmp = word;
                flush(tmp.erase(i, 1), prefix + word[i], length - 1);
            }
        }
    }
}

void            MotLePlusLong::resolve() {
    int         i;

    i = _jeux.length();
    startTimer();
    while (i > 0 && _solution.empty()) {
        flush(_jeux, "", i);
        i--;
    }

    std::cout << "Mot le plus long:" << std::endl;
    std::cout << "\t" << _solution << " en "
    << _solution.length() << " lettre(s)."<< std::endl;
    std::cout.precision(4);
    std::cout << "\tTrouvé en " << std::fixed << _elapsedTime
    << " sec" << std::endl;
    std::cout << "\t" << _tests.size()
    << " combinaisons testées:" << std::endl;
}

void            MotLePlusLong::startTimer() {
    gettimeofday(&_tBegin, NULL);
}

void            MotLePlusLong::stopTimer() {
    gettimeofday(&_tEnd, NULL);
    _elapsedTime = ((double)(1000*(_tEnd.tv_sec-_tBegin.tv_sec)
    +((_tEnd.tv_usec-_tBegin.tv_usec)/1000)))/1000.;
}
