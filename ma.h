#include "StockData.h"

double get_average(std::vector<StockData>& data, int period);
int moving_average_crossover(std::vector<StockData>& data, int ma1, int ma2);