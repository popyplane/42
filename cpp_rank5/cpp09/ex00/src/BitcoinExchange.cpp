#include "../inc/BitcoinExchange.hpp"

std::map<time_t, double>    readCSV(const std::string &csvFile)
{
	std::map<time_t, double>    btcRates;
	std::ifstream               inFile(csvFile.c_str());
	std::string                 line;

	if (!inFile.is_open())
		throw (std::runtime_error(ERR_FILE_OPEN_FAILED + ": " + csvFile));
	if (!std::getline(inFile, line, '\n')) {
		inFile.close();
		throw (std::runtime_error(ERR_FILE_OPEN_FAILED + ": " + csvFile));
	}

	while (std::getline(inFile, line)) {
		size_t  commaIndex = line.find(',');

		if (commaIndex == std::string::npos)
			throw (std::logic_error(ERR_BAD_INPUT + line));
		if (line.empty())
			throw (std::logic_error(ERR_BAD_INPUT + "empty"));

		std::string	subDate = line.substr(0, commaIndex);
		std::string	subRate = line.substr(commaIndex + 1);
		std::string dateStr = trim(subDate);
		std::string rateStr = trim(subRate);
		btcRates.insert(std::make_pair(parseDate(dateStr), parseRate(rateStr)));
	}

	inFile.close();
	return (btcRates);
}

time_t  parseDate(const std::string &dateStr)
{
	if (dateStr.empty())
		throw (std::runtime_error(ERR_BAD_INPUT + "empty date"));
	if (dateStr.size() != 10)
		throw (std::runtime_error(ERR_BAD_INPUT + dateStr));
	
	struct std::tm		tm = {};
	std::istringstream	ss(dateStr);
	char				hyphen1, hyphen2;

	ss >> tm.tm_year >> hyphen1 >> tm.tm_mon >> hyphen2 >> tm.tm_mday;
	if (ss.fail() || hyphen1 != '-' || hyphen2 != '-' || !isValidDate(tm.tm_year, tm.tm_mon, tm.tm_mday))
    	throw std::runtime_error(ERR_BAD_INPUT + dateStr);

	tm.tm_year -= 1900;
	tm.tm_mon -= 1;

	time_t date = mktime(&tm);

	if (date > time(0))
		throw (std::runtime_error("future dates are not supported"));

	return (date);
}

double	parseRate(const std::string &rateStr)
{
	if (rateStr.empty())
		throw (std::runtime_error(ERR_BAD_INPUT + "empty value"));

	std::istringstream	ss(rateStr);
	double				rate;

	if (!isValidRate(rateStr) || !(ss >> rate))
		throw (std::runtime_error(ERR_BAD_INPUT + rateStr));
	if (rate < 0)
		throw (std::runtime_error(ERR_NEGATIVE_NUM));
	if (rate > std::numeric_limits<int>::max())
		throw (std::runtime_error(ERR_TOO_LARGE));

	return (rate);
}

std::string		trim(std::string &str)
{
	size_t	start = 0;

	while (start < str.size() && std::isspace(str[start]))
		start++;

	std::string	leftTrimmed(str.substr(start));
	size_t		end = leftTrimmed.size();

	while (end > 0 && std::isspace(leftTrimmed[end - 1]))
		end--;

	return (leftTrimmed.substr(0, end));
}

bool	isValidDate(int year, int month, int day)
{
	if (year < 1900 || month < 1 || month > 12 || day < 1)
		return false;
	
	const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[month - 1];
	
	if (month == 2 && isLeapYear(year))
		maxDay = 29;

	return (day <= maxDay);
}

bool	isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool	isValidRate(const std::string &rateStr)
{
	bool hasPeriod = false;

	if (rateStr.empty())
    	return (false);

	for (size_t i = 0; i < rateStr.size(); ++i) {
    	if (i == 0 && rateStr[i] == '-')
    		continue;
    	if (rateStr[i] == '.') {
    		if (hasPeriod || i == 0 || i == rateStr.size() - 1)
        		return (false);
    		hasPeriod = true;
    	}
		else if (!std::isdigit(static_cast<unsigned char>(rateStr[i])))
    		return (false);
	}
	return (true);
}

void	processInputFile(const std::string &inputFile, std::map<time_t, double> btcRates)
{
	std::ifstream	inFile(inputFile.c_str());
	std::string		line;

	if (!inFile.is_open())
		throw (std::runtime_error(ERR_FILE_OPEN_FAILED + ": " + inputFile));
	if (!std::getline(inFile, line, '\n')) {
		inFile.close();
		throw (std::runtime_error(ERR_FILE_OPEN_FAILED + ": " + inputFile));
	}
	while (std::getline(inFile, line)) {
		try {
			processLine(line, btcRates);
		} catch (const std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	inFile.close();
}

void	processLine(const std::string &line, std::map<time_t, double> btcRates)
{
	if (line.empty())
		return;
	
	size_t	pipeIndex = line.find('|');

	if (pipeIndex == std::string::npos)
		throw (std::logic_error(ERR_BAD_INPUT + line));

	std::string	subDate = line.substr(0, pipeIndex);
	std::string	subRate = line.substr(pipeIndex + 1);
	std::string dateStr = trim(subDate);
	std::string rateStr = trim(subRate);
	
	time_t	date = parseDate(dateStr);
	double	rate = parseRate(rateStr);
	
	std::map<time_t, double>::iterator	it = btcRates.lower_bound(date);

	if (it == btcRates.end() || it->first > date) {
		if (it == btcRates.begin())
			throw (std::runtime_error("no available exchange rate found."));
		--it;
	}

	double	amount = rate * it->second;

	std::cout << dateStr << " => " << rate << " => " << amount << std::endl;
}