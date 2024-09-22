#include <iostream>
#include <vector>
#include "StockData.h"


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