#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./ScalarConverter <literal>" << std::endl;
        return 1;
    }

    ScalarConverter converter;
    std::string literal = argv[1];
    converter.convert(literal);
    
    return 0;
}