#include "ScalarConverter.hpp"


// bool isSpecialValue(const std::string& str) {
//     return (str == "nan" || str == "nanf" || 
//            str == "inf" || str == "-inf" || 
//            str == "inff" || str == "-inff");
// }

// bool isValidNumber(const std::string& str) {
//     if (str.empty()) return false;
    
//     // Check for special cases first
//     if (isSpecialValue(str)) return true;
    
//     // Check for char literal
//     if (str.length() == 1 && !isdigit(str[0])) return true;
    
//     size_t i = 0;
//     bool hasDigit = false;
//     bool hasDecimal = false;
//     bool hasF = false;
    
//     // Handle sign
//     if (str[i] == '+' || str[i] == '-') {
//         i++;
//         // Only sign is invalid
//         if (i == str.length()) return false;
//     }
    
//     // Check each character
//     for (; i < str.length(); i++) {
//         if (isdigit(str[i])) {
//             hasDigit = true;
//             continue;
//         }
        
//         // Decimal point
//         if (str[i] == '.') {
//             if (hasDecimal || hasF) return false; // Multiple decimals or decimal after f
//             hasDecimal = true;
//             // Decimal at end is invalid (e.g., "123.")
//             if (i == str.length() - 1) return false;
//             continue;
//         }
        
//         // 'f' suffix
//         if (str[i] == 'f') {
//             if (hasF || i != str.length() - 1) return false; // Multiple f's or not at end
//             hasF = true;
//             // Must have digits before f (e.g., ".f" is invalid)
//             if (!hasDigit) return false;
//             continue;
//         }
        
//         // Any other character is invalid
//         return false;
//     }
    
//     // Must have at least one digit (unless it's a single char)
//     return hasDigit || str.length() == 1;
// }

// bool isCharLiteral(const std::string& input) {
//     return (input.length() == 1 && !isdigit(input[0]));
// }

// double stringToDouble(const std::string& str) {
//     if (isSpecialValue(str)) {
//         if (str == "nan" || str == "nanf") 
//             return std::numeric_limits<double>::quiet_NaN();
//         if (str == "inf" || str == "inff") 
//             return std::numeric_limits<double>::infinity();
//         if (str == "-inf" || str == "-inff") 
//             return -std::numeric_limits<double>::infinity();
//     }
    
//     // Handle char literals
//     if (isCharLiteral(str)) {
//         return static_cast<double>(str[0]);
//     }
    
//     // Remove 'f' suffix if present
//     std::string numStr = str;
//     if (!numStr.empty() && numStr.back() == 'f') {
//         numStr = numStr.substr(0, numStr.length() - 1);
//     }
    
//     char* endptr;
//     double value = strtod(numStr.c_str(), &endptr);
    
//     // Check if conversion consumed entire string
//     if (*endptr != '\0') {
//         throw std::invalid_argument("Invalid numeric format");
//     }
    
//     return value;
// }

// std::string formatCharOutput(char c) {
//     if (!isprint(c)) 
//         return "Non displayable";
//     std::string result = "'";
//     result += c;
//     result += "'";
//     return result;
// }

// void printCharConversion(double value) {
//     std::cout << "char: ";

//     if (isnan(value) || isinf(value))
//         std::cout << "impossible";
//     else if (value < std::numeric_limits<char>::min() || 
//              value > std::numeric_limits<char>::max())
//         std::cout << "impossible";
//     else
//         std::cout << formatCharOutput(static_cast<char>(value));
//     std::cout << std::endl;
// }

// void printIntConversion(double value) {
//     std::cout << "int: ";
//     if (isnan(value) || isinf(value))
//         std::cout << "impossible";
//     else if (value < std::numeric_limits<int>::min() || 
//              value > std::numeric_limits<int>::max())
//         std::cout << "impossible";
//     else 
//         std::cout << static_cast<int>(value);
//     std::cout << std::endl;
// }

// void printFloatConversion(double value) {
//     std::cout << "float: ";
//     if (isnan(value))
//         std::cout << "nanf";
//     else if (isinf(value))
//         std::cout << (value < 0 ? "-inff" : "inff");
//     else {
//         float f = static_cast<float>(value);
//         std::cout << f;
//         if (f == floorf(f) && f < 1e6 && f > -1e6) 
//             std::cout << ".0";
//         std::cout << "f";
//     }
//     std::cout << std::endl;
// }

// void printDoubleConversion(double value) {
//     std::cout << "double: ";
//     if (isnan(value))
//         std::cout << "nan";
//     else if (isinf(value))
//         std::cout << (value < 0 ? "-inf" : "inf");
//     else {
//         std::cout << value;
//         if (value == floor(value) && value < 1e6 && value > -1e6)
//             std::cout << ".0";
//     }
//     std::cout << std::endl;
// }

// void ScalarConverter::convert(const std::string& input) {
//     try {
//         if (!isValidNumber(input)) {
//             throw std::invalid_argument("Invalid input format");
//         }
        
//         double value = stringToDouble(input);
        
//         printCharConversion(value);
//         printIntConversion(value);
//         printFloatConversion(value);
//         printDoubleConversion(value);
//     } catch (const std::exception& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//         std::cout << "char: impossible" << std::endl;
//         std::cout << "int: impossible" << std::endl;
//         std::cout << "float: impossible" << std::endl;
//         std::cout << "double: impossible" << std::endl;
//     }
// }