#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) 
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) 
{
    (void)other;
    return *this;
}


bool isSpecialValue(const std::string& str) 
{
    return (str == "nan" || str == "nanf" || 
           str == "inf" || str == "-inf" || 
           str == "inff" || str == "-inff" ||
           str == "+inf" || str == "+inff");
}


void ScalarConverter::convert(const std::string& input) 
{
    try 
    {
        if (!isValidNumber(input))
            throw std::invalid_argument("Invalid input format");
        
        double value = stringToDouble(input);
        
        printCharConversion(value);
        printIntConversion(value);
        printFloatConversion(value);
        printDoubleConversion(value);
    } catch (const std::exception& e) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}