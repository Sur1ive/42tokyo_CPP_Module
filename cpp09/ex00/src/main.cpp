#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <data_file>\n";
    return 1;
  }

  std::ifstream dataFile(argv[1]);
  if (!dataFile.is_open()) {
    std::cerr << "Error: could not open file\n";
    return 1;
  }

  try {
    BitcoinExchange rateData("src/data.csv");
    rateData.printData(dataFile);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}
