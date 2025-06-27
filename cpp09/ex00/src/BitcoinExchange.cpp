#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange(const std::string &rateFile) {
  std::ifstream file(rateFile.c_str());
  if (!file.is_open())
    throw std::runtime_error("Error: Failed to open rate file");

  std::string line;
  std::getline(file, line);
  if (line != "date,exchange_rate")
    throw std::runtime_error("Error: Invalid header");

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string date;
    std::string rate;
    std::getline(ss, date, ',');
    std::getline(ss, rate);
    data_[date] = strtod(rate.c_str(), NULL);
  }
  file.close();
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::getRate(const std::string &date) const {
  const_iterator it = data_.find(date);
  if (it == data_.end()) {
    const_iterator upper = data_.upper_bound(date);
    if (upper == data_.begin())
      return 0;
    --upper;
    return upper->second;
  }
  return it->second;
}

// YYYY-MM-DD
bool BitcoinExchange::isDateValid(const std::string &date) {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    return false;
  for (int i = 0; i < 10; i++) {
    if (i == 4 || i == 7)
      continue;
    if (!isdigit(date[i]))
      return false;
  }
  std::stringstream ss(date);
  int year, month, day;
  char dash;
  ss >> year >> dash >> month >> dash >> day;
  if (ss.fail())
    return false;
  int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    days_in_month[1] = 29;
  if (year < 2009 || year > 2025 || month < 1 || month > 12 || day < 1 ||
      day > days_in_month[month - 1])
    return false;
  return true;
}

// 0~1000
bool BitcoinExchange::isValueValid(const std::string &value) {
  if (value.empty())
    return false;

  std::stringstream ss(value);
  std::string integer;
  std::getline(ss, integer, '.');
  if (integer.length() > 4)
    return false;

  int dot_count = 0;
  for (size_t i = 0; i < value.length(); i++) {
    if (!isdigit(value[i])) {
      if (value[i] == '.') {
        dot_count++;
        if (dot_count == 1 && i != 0 && i != value.length() - 1)
          continue;
      }
      return false;
    }
  }

  double d = strtod(value.c_str(), NULL);
  if (d < 0 || d > 1000)
    return false;

  return true;
}

void BitcoinExchange::printData(std::ifstream &dataFile) {
  std::string line;
  std::getline(dataFile, line);
  if (line != "date | value") {
    throw std::runtime_error("Error: Invalid header");
  }

  while (std::getline(dataFile, line)) {
    std::stringstream ss(line);
    std::string date, value;
    std::getline(ss, date, '|');
    if (date.length() != 11 || date[10] != ' ') {
      std::cerr << "Error: bad input, expected \"YYYY-MM-DD | value\", got \""
                << line << "\"\n";
      continue;
    }
    date = date.substr(0, 10);
    if (!BitcoinExchange::isDateValid(date)) {
      std::cerr << "Error: date is not valid, got \"" << date << "\"\n";
      continue;
    }

    std::getline(ss, value);
    if (value.empty() || value[0] != ' ') {
      std::cerr << "Error: bad input, expected \"YYYY-MM-DD | value\", got \""
                << line << "\"\n";
      continue;
    }
    value = value.substr(1);
    if (!BitcoinExchange::isValueValid(value)) {
      std::cerr
          << "Error: value is not valid, expected 0~1000 without sign, got \""
          << value << "\"\n";
      continue;
    }
    double rate = getRate(date);
    double result = strtod(value.c_str(), NULL) * rate;
    std::cout << date << " => " << value << " = " << result << '\n';
  }
}
