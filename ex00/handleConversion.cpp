
#include "ScalarConverter.hpp"

int isValidNumber(const std::string& str) 
{
    if (str.empty())
        return 0;    
    if (isSpecialValue(str))
        return 1;
    if (str.length() == 1 && !isdigit(str[0])) 
        return 1;
    
    size_t i = 0;
    int hasDigit = 0;
    int hasDecimal = 0;
    int hasF = 0;
    
    if (str[i] == '+' || str[i] == '-') 
    {
        i++;
        if (i == str.length()) 
            return 0;
    }
    
    if (str[i] == '.') 
    {
        if (i == str.length() - 1) 
            return 0;
        hasDecimal = 1;
        i++;
    }
    if(str[0] == '.') 
        return 0;
    if(str[str.length() - 1] == 'f' && str[str.length() - 2] == '.')
        return 0;
    
    for (; i < str.length(); i++) 
    {
        if (isdigit(str[i])) 
        {
            hasDigit = 1;
            continue;
        }
        
        if (str[i] == '.') 
        {
            if (hasDecimal || hasF) 
                return 0;
            hasDecimal = 1;
            if (i == str.length() - 1) 
                return 0;
            continue;
        }
        if (str[i] == 'f') 
        {
            if (hasF || i != str.length() - 1) 
                return 0;
            hasF = 1;
            if (!hasDigit) 
                return 0;
            continue;
        }
        return 0;
    }
    return (hasDigit || str.length() == 1);
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
        if (str == "inf" || str == "inff" || str =="+inf" || str == "+inff") 
            return std::numeric_limits<double>::infinity();
        if (str == "-inf" || str == "-inff") 
            return -std::numeric_limits<double>::infinity();
    }
    
    if (isCharLiteral(str))
        return static_cast<double>(str[0]);
    
    std::string numStr = str;
    if (!numStr.empty() && numStr[numStr.length() - 1] == 'f')
        numStr = numStr.substr(0, numStr.length() - 1);
    
    char* endptr;
    double value = strtod(numStr.c_str(), &endptr);
    
    if (*endptr != '\0')
        throw std::invalid_argument("Invalid numeric format");
    return value;
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

    if (isnan(value) || isinf(value) ||
        value < std::numeric_limits<char>::min() || 
        value > std::numeric_limits<char>::max())
        std::cout << "impossible";
    else
        std::cout << formatCharOutput(static_cast<char>(value));
    std::cout << std::endl;
}

void printIntConversion(double value) 
{
    std::cout << "int: ";
    if (isnan(value) || isinf(value) ||
        value < std::numeric_limits<int>::min() || 
        value > std::numeric_limits<int>::max())
        std::cout << "impossible";
    else 
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
}

void printFloatConversion(double value) 
{
    std::cout << "float: ";
    
    if (std::isnan(value))
        std::cout << "nanf";
    else if (std::isinf(value))
        std::cout << "impossible";
    else if (value > std::numeric_limits<float>::max() || 
             value < -std::numeric_limits<float>::max()) {
        std::cout << "impossible";
    }
    else 
    {
        float f = static_cast<float>(value);

        std::ostringstream oss;
        oss  << f;
        std::string s = oss.str();
        size_t dot_pos = s.find('.');
        if (dot_pos != std::string::npos) {
            s.erase(s.find_last_not_of('0') + 1, std::string::npos);
            if (!s.empty() && s[s.length()-1] == '.') {
                s.erase(s.end() - 1);
            }
        }
        if (s.find('.') == std::string::npos)
            std::cout << s << ".0f";
        else 
            std::cout << s << "f";
    }
    std::cout << std::endl;
}

void printDoubleConversion(double value) 
{
    std::cout << "double: ";
    
    if (std::isnan(value))
        std::cout << "nan";
    else if (std::isinf(value))
        std::cout << "impossible";

    else {
        std::ostringstream oss;
        oss  << value;
        std::string s = oss.str();
        size_t dot_pos = s.find('.');
    
        if (dot_pos != std::string::npos) 
        {
            s.erase(s.find_last_not_of('0') + 1, std::string::npos);
            if (!s.empty() && s[s.length()-1] == '.') {
                s.erase(s.end() - 1);
            }
        }
        if (s.find('.') == std::string::npos)
            std::cout << s << ".0";
        else 
            std::cout << s << "";
    }
    std::cout << std::endl;
}