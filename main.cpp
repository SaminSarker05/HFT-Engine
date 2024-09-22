#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "StockData.h"
#include "ma_signal.h"
#include "volume_signal.h"
#include <thread>

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
};

void process_stock(const std::string& ticker) 
{
  auto stock_data = get_data(ticker);
  std::cout << "ma " << ticker << ": " << moving_average_crossover(stock_data, 5, 10) << std::endl;
  std::cout << "volume " << ticker << ": " << volume_check(stock_data, 20) << std::endl;

}


int main() 
{
  std::thread MSFT(process_stock, "MSFT.csv");
  std::thread AAPL(process_stock, "AAPL.CSV");

  MSFT.join();
  AAPL.join();

  return 0;
}