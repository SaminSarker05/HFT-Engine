#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

struct StockData {
  std::string date;
  double open;
  double high;
  double low;
  double close;
  double adj_close;
  int volume;
};

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

double get_average(std::vector<StockData>& data, int period) 
{
  double total = 0;
  for (int i = 0; i < period; ++i) {
    total += data[i].close;
  }
  return total / period;
};

int moving_average_crossover(std::vector<StockData>& data, int ma1, int ma2) 
{
  double short_ma = get_average(data, ma1);
  double long_ma = get_average(data, ma2);

  if (short_ma < long_ma) {
    std::cout << "buy" << std::endl;
    return 1;
  } else if (short_ma > long_ma){
    std::cout << "sell" << std::endl;
    return -1;
  }
  std::cout << "hold" << std::endl;
  return 0;
}


int main() 
{
  auto stock_data = get_data("MSFT.csv");
  int signal = moving_average_crossover(stock_data, 5, 10);
  std::cout << signal << std::endl;
}