
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <string>

typedef enum { EXIT, HELP, ERROR } Command;

class Application
{
private:
    bool        _running;
    std::string _prompt;
    std::string _input;

public:
    Application();
    virtual ~Application();

    void        start();
    void        loop();
    void        stop();
    void        help();

private:
    void        execute();
};

#endif /* !APPLICATION_HPP_ */
