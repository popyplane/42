#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdlib.h>
# include <iostream>

# define uintptr_t unsigned long

using std::string;
using std::cout;
using std::endl;

struct Data
{
	string	name;
	int		id;
};

class Serializer
{
	private :
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer &operator=(const Serializer &src);

	public :
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif