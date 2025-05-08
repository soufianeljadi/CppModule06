#include "ScalarConverter.hpp"

void printChar(char c) 
{
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else 
        std::cout << "char: Non displayable" << std::endl;

}

void printInt(int i) 
{
    std::cout << "int: " << i << std::endl;
}

void printFloat(float f) 
{
    if (f == static_cast<int>(f))
        std::cout << "float: " << f << ".0f" << std::endl;
    else 
        std::cout << "float: " << f << "f" << std::endl;

}

void printDouble(double d) 
{
    if (d == static_cast<int>(d))
        std::cout << "double: " << d << ".0" << std::endl;
    else 
        std::cout << "double: " << d << std::endl;
}


void handleConversion(std::string &literal) 
{
    char c;
    int i;
    float f;
    double d;
    
    if (literal.length() == 1 && !isdigit(literal[0])) 
    {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } 
    else 
    {
        i = std::atoi(literal.c_str());
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }

    printChar(c);
    printInt(i);
    printFloat(f);
    printDouble(d);
}

