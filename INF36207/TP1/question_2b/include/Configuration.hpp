
#ifndef CONFIGURATION_HH_
#define CONFIGURATION_HH_

#include <string>

typedef unsigned int    uint;

namespace constants
{
    static const std::string DICTIONNARY = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%&*";
    static const std::string PROCESSOR_FILE = "/proc/cpuinfo";
    static const std::string PROCESSOR = "processor";
    static const uint DEFAULT_PROCESSOR_NBR = 2;

    namespace characters
    {
        static const char COLUMN = ':';
    }

}

class Configuration
{
private:
    std::string     _dictionnary;
    uint            _processors;

public:
    Configuration(const std::string &, const std::string & = constants::PROCESSOR_FILE);
    ~Configuration();

    const std::string   &getDictionnary() const;
    uint                getProcessors() const;
};

#endif /* !CONFIGURATION_HH_ */
