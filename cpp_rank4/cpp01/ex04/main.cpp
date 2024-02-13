#include <iostream>
#include <fstream>
#include <string>

using	std::cout;
using	std::cerr;
using	std::endl;
using	std::string;

int main(int ac, char **av)
{
	if (ac != 4)
	{
		cerr << "./replace <filename> <string1> <string2>" << endl;
		exit(EXIT_FAILURE);
	}
	

	string	filename = av[1];
	string	current = av[2];
	string	replace = av[3];

	std::ifstream	filein(filename);	
	if (!filein)
	{
		cerr 
			<< "Make sure " << av[1] << " exists and you have acces"
			<< endl;
		exit(EXIT_FAILURE);
	}
	
	std::ofstream	fileout(filename.append(".replace"));
	string	line;
	size_t	pos;

	while(getline(filein, line))
	{
		pos = line.find(current);
		while (pos != string::npos)
		{
			line.erase(pos, current.length());
			line.insert(pos, replace);
			pos = line.find(current, pos + replace.length());
		}
		fileout << line << endl;
	}
	filein.close();
	fileout.close();
}