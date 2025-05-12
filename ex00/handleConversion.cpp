#include "ScalarConverter.hpp"

bool isSpecialValue(const std::string& str) 
{
    return (str == "nan" || str == "nanf" || 
           str == "inf" || str == "-inf" || 
           str == "inff" || str == "-inff");
}

bool isCharLiteral(const std::string& input) 
{
    return (input.length() == 1 && !isdigit(input[0]));
}

double stringToDouble(const std::string& str) 
{
    if (isSpecialValue(str)) 
    {
        if (str == "nan" || str == "nanf") 
            return std::numeric_limits<double>::quiet_NaN();
        if (str == "inf" || str == "inff") 
            return std::numeric_limits<double>::infinity();
        if (str == "-inf" || str == "-inff") 
            return -std::numeric_limits<double>::infinity();
    }
    return (std::atof(str.c_str()));
}

std::string formatCharOutput(char c) 
{
    if (!isprint(c)) 
        return "Non displayable";
    std::string result = "'";
    result += c;
    result += "'";
    return result;
}

void printCharConversion(double value) 
{
    std::cout << "char: ";

    if (isnan(value))
        std::cout << "Non displayable";
    else if (value < std::numeric_limits<char>::min() || 
             value > std::numeric_limits<char>::max())
        std::cout << "Non displayable";
    else
        std::cout << formatCharOutput(static_cast<char>(value));
    std::cout << std::endl;
}

void printIntConversion(double value) 
{
    std::cout << "int: ";
    if (isnan(value) || isinf(value))
        std::cout << "impossible";
    else if (value < std::numeric_limits<int>::min() || 
             value > std::numeric_limits<int>::max())
        std::cout << "impossible";
    else 
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
}

void printFloatConversion(double value) 
{
    std::cout << "float: ";
    if (isnan(value))
        std::cout << "nanf";
    else if (isinf(value))
        std::cout << (value < 0 ? "-inff" : "inff");
    else 
    {
        float f = static_cast<float>(value);
        std::cout << f;
        if (f == floorf(f)) 
            std::cout << ".0";
        std::cout << "f";
    }
    std::cout << std::endl;
}

void printDoubleConversion(double value) 
{
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(6);
    if (isnan(value))
        std::cout << "nan";
    else if (isinf(value))
        std::cout << (value < 0 ? "-inf" : "inf");
    else 
    {
        std::cout << value;
        if (value == floor(value))
            std::cout << ".0";
    }
    std::cout << std::endl;
}

