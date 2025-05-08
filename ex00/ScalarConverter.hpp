#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);

        static void convert( std::string &literal);

};

// handleConversion
void printChar(char c);
void printInt(int i);
void printFloat(float f);
void printDouble(double d);
void handleConversion(std::string &literal);

#endif