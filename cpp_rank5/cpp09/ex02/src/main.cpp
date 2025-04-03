#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: \"positive integer values to be sorted\"\n";
		return 1;
	}

	try {
		std::vector<int>	vec;
		parseInput(argc, argv, vec);
		std::deque<int>		deq(vec.begin(), vec.end());

		printContainer("Before :", vec);

		double	timeVec = getSortTime(vec);
		double	timeDeq = getSortTime(deq);

		printContainer("After :", vec);

		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}