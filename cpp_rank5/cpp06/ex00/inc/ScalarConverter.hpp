#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <climits>
# include <cfloat>

using std::string;
using std::cout;
using std::endl;

class ScalarConverter
{
    private :
    // canon
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &src);

    // utils
    void    toChar(const char *input_char, double input_double);
    void    toInt(const char *input_char, double input_double);
    void    toFloat(const char *input_char, double input_double);
    void    toDouble(const char *input_char, double input_double);
    bool    isLimit(const string input);
    void    castLimit(const string input);
    
    public :
    // methods
    static void    convert(const string literal);
}

#endif