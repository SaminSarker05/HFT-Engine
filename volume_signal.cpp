#include <iostream>
#include <vector>
#include "StockData.h"

int volume_check(std::vector<StockData>& data, int period) {
  long total_volume = 0;
  for (int i = 0; i < period; ++i) {
    total_volume += data[i].volume;
  }
  long avg_volume = total_volume / period;

  if (data[0].volume > avg_volume * 1.5) {
    return 1;
  } else if (data[0].volume < avg_volume * 0.5) {
    return -1;
  }
  return 0;
}