#ifndef MOTLEPLUSLONG_HPP
#define MOTLEPLUSLONG_HPP

#include <iostream>
#include <string>
#include <list>
#include <sys/time.h>

#include "Dict.hpp"

class           MotLePlusLong {
private:
    const Dict*             _dict;
    std::string             _jeux;
    std::string             _solution;
    std::list<std::string>  _tests;
    timeval                 _tBegin;
    timeval                 _tEnd;
    double                  _elapsedTime;

    bool        testJeux();
    void        flush(std::string word, std::string prefix, int length);
    void        startTimer();
    void        stopTimer();
public:
    MotLePlusLong (const Dict *dict);
    virtual ~MotLePlusLong ();

    void        resolve();
};

#endif
