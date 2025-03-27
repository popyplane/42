#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cerr << "Input file is needed" << std::endl;
	} else if (argc > 2) {
		std::cerr << "Too many arguments" << std::endl;
	} else if (argc == 2) {
		try {
			std::map<time_t, double>    btcRates = readCSV("data.csv");
			processInputFile(argv[1], btcRates);
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}