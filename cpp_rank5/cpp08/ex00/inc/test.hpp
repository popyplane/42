#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <string>
# include "easyfind.hpp"

template <typename T>
void    setupContainer(T &t)
{
	const int   MAX_CONTAINER_SIZE = 10;
	for (int i = 0; i < MAX_CONTAINER_SIZE; i++)
		t.push_back(i);
}

template <typename T>
void    displayContainer(T &t, const std::string &type)
{
	std::cout << std::endl << "=== Testing " << type << " ===" << std::endl;
	std::cout << "Values :";
	for (typename T::iterator it = t.begin(); it != t.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

template <typename T>
void    displayContainer(const T &t, const std::string &type)
{
    std::cout <<std::endl << "=== Testing " << type << " ===" << std::endl;
    std::cout << "Values :";
    for (typename T::const_iterator it = t.begin(); it != t.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}

template <typename T>
void    testEasyFind(T &t, int n)
{
	std::cout << "Searching " << n << " ..." << std::endl;
	try
	{
		std::cout << *(easyfind(t, n)) << " is found !" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template <typename T>
void    testEasyFind(const T &t, int n)
{
	std::cout << "Searching " << n << " ..." << std::endl;
	try
	{
		std::cout << *(easyfind(t, n)) << " is found !" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


#endif