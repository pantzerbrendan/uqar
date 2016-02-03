#include <iostream>

#include <string>
#include <fstream>
#include <cstddef>
#include <sstream>
#include "Application.hh"
#include "data/User.hh"
#include "utils/utils.hh"

namespace io
{
    bool        save_data(const std::string &filename, User **data, size_t size)
    {
        std::ofstream   fileStream(filename.c_str(), std::ios::out);
        if (fileStream)
        {
            fileStream << size << std::endl;
            for (size_t index = 0; data[index]; index++)
                fileStream << data[index]->CSVFormatter(data[index]) << std::endl;
            fileStream.close();
            return (true);
        }

        return (false);
    }

    std::string     *read_data(const std::string &filename)
    {
        std::ifstream   fileStream(filename.c_str(), std::ios::in);

        if (fileStream)
        {
            std::string line;
            getline(fileStream, line);
            size_t  size;
            std::istringstream(line) >> size;
            std::string *array = new std::string[size];

            size_t row = 0;
            while (getline(fileStream, line))
                array[row++] = line;
            fileStream.close();
            return (array);
        }
        return NULL;
    }

    size_t      count_lines(const std::string &filename)
    {
        std::ifstream   fileStream(filename.c_str(), std::ios::in);
        if (fileStream)
        {
            size_t count = 0;
            std::string line;
            while (getline(fileStream, line)) count++;
            fileStream.close();
            return (--count);
        }
        return (0);
    }
}
