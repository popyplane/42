#include "../inc/Iter.hpp"

int main()
{
	int	array[] = {1, 2, 3, 4, 5, 6, 7};
	int	array_length = sizeof(array) / sizeof(int);
	
	std::cout << "array length : " << array_length << std::endl;
	iter(array, array_length, ft_print<int>);
	std::cout << std::endl;
	
	std::string array2[] = {"str1", "str2", "str3", "str4"};
	int	array2_length = sizeof(array2) / sizeof(std::string);

	std::cout << "array length : " << array2_length << std::endl;
	iter(array2, array2_length, ft_print<std::string>);
	return (0);
}