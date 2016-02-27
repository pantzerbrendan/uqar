
#ifndef LOGGING_HH_
# define LOGGING_HH_

#include <map>
#include <string>

/*
namespace Log {
    typedef enum {
        DEBUG, INFO, WARNING, ERROR, FATAL
    } LogLevel;
}

#define MIN_LOG (Log::WARNING)

class Logging {
private:
    Logging ();
    virtual ~Logging ();

    static const Log::LogLevel _minLog = MIN_LOG; // defined at compilation
    static const std::map<Log::LogLevel, std::string> _logColors {
            { Log::DEBUG, "\033[32m" },
            { Log::INFO, "\033[36m" },
            { Log::WARNING, "\033[33m" },
            { Log::ERROR, "\033[1;31m" },
            { Log::FATAL, "\033[31m" }
    };

public:
    static void Log(const Log::LogLevel, const std::string &);


};
*/
#endif /* !LOGGING_HH_ */
