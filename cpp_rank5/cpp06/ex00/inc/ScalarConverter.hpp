#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <climits>
# include <cfloat>
# include <cstdlib>

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
	static void	toChar(const char *input_char, double input_double);
	static void	toInt(const char *input_char, double input_double);
	static void	toFloat(const char *input_char, double input_double);
	static void	toDouble(const char *input_char, double input_double);
	static bool	isLimit(const string input);
	static int	calculateFormat(const char *input_char);
	static void	castLimit(const string input);
	
	public :
	// methods
	static void    convert(const string literal);
};

#endif