/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:41:32 by bvieilhe          #+#    #+#             */
/*   Updated: 2025/04/17 09:41:33 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <cctype>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <limits>
# include <map>
# include <sstream>
# include <string>
# include <exception>

# define ERR_FILE_OPEN_FAILED std::string("could not open file")
# define ERR_BAD_INPUT std::string("bad input => ")
# define ERR_NEGATIVE_NUM std::string("not a positive number.")
# define ERR_TOO_LARGE std::string("too large a number.")

std::map<time_t, double>    readCSV(const std::string &csvFile);
time_t                      parseDate(const std::string &dateStr);
double                      parseRate(const std::string &rateStr);
std::string                 trim(std::string &str);

void	processInputFile(const std::string &inputFile, std::map<time_t, double> btcRates);
void	processLine(const std::string &lineinputFile, std::map<time_t, double> btcRates);

bool	isValidDate(int year, int month, int day);
bool	isLeapYear(int year);
bool	isValidRate(const std::string &rateStr);

#endif