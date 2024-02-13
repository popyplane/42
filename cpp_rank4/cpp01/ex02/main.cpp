# include <string>
# include <iostream>

int main()
{
	std::string     str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << std::endl
		<< "str adress     : " << &str << std::endl
		<< "with stringPTR : " << stringPTR << std::endl
		<< "with strinfREF : " << &stringREF << std::endl
		<<std::endl;
	
	std::cout
		<< "str value      : " << str << std::endl
		<< "with stringPTR : " << *stringPTR << std::endl
		<< "with stringREF : " << stringREF << std::endl
		<< std::endl;
}