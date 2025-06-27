#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
public:
  BitcoinExchange(const std::string &rateFile);
  ~BitcoinExchange();

  typedef std::map<std::string, double>::const_iterator const_iterator;
  typedef std::map<std::string, double>::iterator iterator;

  double getRate(const std::string &date) const;
  void printData(std::ifstream &dataFile);

  static bool isValueValid(const std::string &value);
  static bool isDateValid(const std::string &date);

private:
  std::map<std::string, double> data_;

  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
};

#endif
