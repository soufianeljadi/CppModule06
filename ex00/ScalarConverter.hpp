#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cmath>
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

int isValidNumber(const std::string& str);
bool isSpecialValue(const std::string& str);
double stringToDouble(const std::string& str);
void printCharConversion(double value);
void printIntConversion(double value);
void printFloatConversion(double value);
void printDoubleConversion(double value);
bool isCharLiteral(const std::string& input);

#endif