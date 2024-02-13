#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

using std::string;
using std::cout;
using std::endl;

class Harl
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		void	complain(string level);

		Harl();
		~Harl();
};

#endif