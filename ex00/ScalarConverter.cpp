#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) 
{
    (void)other;
    return *this;
}


void ScalarConverter::convert(const std::string& input) 
{
    if (input.empty()) 
    {
        std::cout << "Error: empty input" << std::endl;
        return;
    }

    double numericValue;

    if (isCharLiteral(input))
        numericValue = static_cast<double>(input[0]);
    else
        numericValue = stringToDouble(input);

    printCharConversion(numericValue);
    printIntConversion(numericValue);
    printFloatConversion(numericValue);
    printDoubleConversion(numericValue);
}