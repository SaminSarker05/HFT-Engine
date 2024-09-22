#ifndef STOCKDATA_H
#define STOCKDATA_H

#include <string>

struct StockData {
  std::string date;
  double open;
  double high;
  double low;
  double close;
  double adj_close;
  int volume;
};

#endif