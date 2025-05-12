#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <limits>
#include <sstream>
#include <cmath>

#include <cctype>
#include <limits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

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