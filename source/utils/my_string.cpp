#include <iostream>

#include <string>
#include <cstddef>
#include "utils/utils.hh"

namespace my_string
{

    std::string     *split(const std::string &str, char delimiter)
    {
        size_t size = countDelimiter(str, delimiter) + 1;
        std::string *array = new std::string[size];
        std::string tmp = str;
        size_t idx = 0;
        size_t index;
        while ((index = tmp.find_first_of(delimiter)) != std::string::npos)
        {
            array[idx++] = tmp.substr(0, index);
            tmp = tmp.substr(index + 1);
        }
        array[idx] = tmp;
        if (idx == size - 1)
            return (array);
        delete[] array;
        return (NULL);
    }

    size_t          countDelimiter(const std::string &str, char delimiter)
    {
        size_t count = 0;
        for (size_t index = 0; index < str.size(); index++)
            if (str[index] == delimiter) count++;
        return (count);
    }

    bool            isNumber(const std::string &str)
    {
        for(size_t index = 0; index < str.size(); index++)
        {
            if (str[index] > '9' || str[index] < '0')
                if (str[index] != '-')
                    return (false);
        }
        return (true);
    }

}
