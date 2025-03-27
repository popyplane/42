#include "../inc/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN \"input\"\n";
		return 1;
	}
	try {
		calculateRPN(argv[1]);
	} catch (const std::exception &e) {
		std::cout << "Error: " << e.what() << "\n";
		return 1;
	}
	return 0;
}