#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "StockData.h"
#include "ma.h"

std::vector<StockData> get_data(const std::string& ticker) 
{
  std::ifstream file(ticker);
  if (!file) {
    std::cerr << "error opening file for " << ticker << std::endl;
  }
  std::string line;
  std::getline(file, line);   // skip header file

  std::vector<StockData> data;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string column;
    StockData row;
    std::getline(ss, row.date, ',');
    std::getline(ss, column, ','); row.open = std::stod(column);
    std::getline(ss, column, ','); row.high = std::stod(column);
    std::getline(ss, column, ','); row.low = std::stod(column);
    std::getline(ss, column, ','); row.close = std::stod(column);
    std::getline(ss, column, ','); row.adj_close = std::stod(column);
    std::getline(ss, column, ','); row.volume = std::stol(column);
    data.push_back(row);
  }

  file.close();
  return data;
}


int main() 
{
  auto stock_data_MSFT = get_data("MSFT.csv");
  auto stock_data_AAPL = get_data("AAPL.csv");
  int signal_MFST = moving_average_crossover(stock_data_MSFT, 5, 10);
  int signal_AAPL = moving_average_crossover(stock_data_AAPL, 5, 10);
  std::cout << signal_MFST << std::endl;
  std::cout << signal_AAPL << std::endl;
}