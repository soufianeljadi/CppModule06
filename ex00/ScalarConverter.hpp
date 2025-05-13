#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cctype>
#include <stdexcept>
#include <limits>

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);

        static void convert(const std::string &input);

};

#endif