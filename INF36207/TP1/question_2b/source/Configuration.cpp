
#include <iostream>

#include <string>
#include <fstream>
#include "Configuration.hpp"
#include "utils/Colors.hpp"

static uint         getProcessorsNumber(const std::string &filename)
{
    std::fstream fs(filename.c_str(), std::fstream::in);
    if (fs)
    {
        std::string line;
        uint nbr = 0;
        while (getline(fs, line))
        {
            if (line.find(constants::PROCESSOR) != std::string::npos)
                nbr++;
        }

        fs.close();
        return (nbr);
    }
    return (constants::DEFAULT_PROCESSOR_NBR);
}

Configuration::Configuration(const std::string &dictionnary, const std::string &filename)
{
    this->_dictionnary = dictionnary;
    this->_processors = getProcessorsNumber(filename);
#ifdef DEBUG
    std::clog << colors::green << "[" << __FUNCTION__ << "] Done : _dictionnary(" << this->_dictionnary << "), _processors(" << this->_processors << ")" << colors::reset << std::endl;
#endif
}

Configuration::~Configuration()
{

}

const std::string   &Configuration::getDictionnary() const { return (this->_dictionnary); }
uint                Configuration::getProcessors() const { return (this->_processors); }
