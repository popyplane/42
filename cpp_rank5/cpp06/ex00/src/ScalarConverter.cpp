#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	*this = src;
}

void	ScalarConverter::toChar(const char *input_char, double input_double)
{
	cout << "char : ";
	if (!is_digit(input_char[0]) && !input_char[1])
		cout << "'" << input_char[0] << "'";
	else if (input_double < 0 || input_double >= MAX_CHAR)
		cout << "impossible";
	else if (input_double >= 0 && input_double <= 32)
		cout << "Non displayable";
	else
		cout << "'" << static_cast<char>(input_double) << "'";
	cout << endl;
}

void	ScalarConverter::toInt(const char *input_char, double input_double)
{
	cout << "int : ";
	if (!is_digit(input_char[0]) && !input_char[1])
		cout << static_cast<int>(input_char[0]);
	else if (input_double < INT_MIN || input_double > INT_MAX)
		cout << "Impossible";
	else
		cout << static_cast<int>(input_double);
	cout << endl;
}

void	ScalarConverter::toFloat(const char *input_char, double input_double)
{
	cout << "float : ";
	if (!is_digit(input_char[0]) && !input_char[1])
		cout << static_cast<float>(input_char[0]);
	else if (input_double < -FLT_MAX || input_double > FLT_MAX)
		cout << "Impossible";
	else
		cout << static_cast<float>(input_double);
	cout << endl;
}

void	ScalarConverter::toDouble(const char *input_char, double input_double)
{
	cout << "double : ";
	if (!is_digit(input_char[0]) && !input_char[1])
		cout << static_cast<double>(input_char[0]);
	else if (input_double < -DBL_MAX || input_double > DBL_MAX)
		cout << "Impossible";
	else
		cout << static_cast<double>(input_double);
	cout << endl;
}

bool	ScalarConverter::isLimit(const string input)
{
	return (input == "+inf" || input == "-inf" || input == "nan" || input == "+inff" || input == "-inff" || input == "nanf");
}

void	ScalarConverter::castLimit(const string input)
{
	cout << "char : Impossible" << endl << "int : Impossible" << endl;
	if (input == "nan" || input == "nanf")
		cout << "float : nanf" << endl << "double : nan" << endl;
	else if (input == "+inf" || input == "+inff")
		cout << "float : +inff" << endl << "double : +inf" << endl;
	else if (input == "-inff" || input == "-inf")
		cout << "float : -inff" << endl << "double : -inf" << endl;
}

void	ScalarConverter::convert(const string literal)
{
	const char	*input_char = literal.c_str();
	double	input_double = std::strtod(input_char, NULL);

	if (isLimit(literal))
		castLimit(literal);
	else
	{
		toChar(input_char, input_double);
		toInt(input_char, input_double);
		toFloat(input_char, input_double);
		toDouble(input_char, input_double);
	}
}
