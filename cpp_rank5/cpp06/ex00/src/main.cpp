#include "../inc/ScalarConverter.hpp"

int main()
{
	try
	{
		ScalarConverter::convert("0");
        cout << endl;
		ScalarConverter::convert("3.14f");
        cout << endl;
		ScalarConverter::convert("3.14");
        cout << endl;
		ScalarConverter::convert("a");
        cout << endl;
		ScalarConverter::convert("-128");
        cout << endl;
		ScalarConverter::convert("999999999");
        cout << endl;
		ScalarConverter::convert("42");
        cout << endl;
		ScalarConverter::convert("3.14f5");
        cout << endl;
		ScalarConverter::convert("3.14d");
        cout << endl;
		ScalarConverter::convert("-inf");
        cout << endl;
		ScalarConverter::convert("+inf");
        cout << endl;
		ScalarConverter::convert("+inff");
        cout << endl;
		ScalarConverter::convert("-inff");
        cout << endl;
		ScalarConverter::convert("nan");
        cout << endl;
		ScalarConverter::convert("nanf");
    }
    catch (std::exception const &e)
    {std::cerr << e.what() << endl;}
    
    return (0);
}