#include <cfloat>
#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
int main() {
  MerkelMain merkelMain;
  merkelMain.init();
  CSVReader::readCSV("1XejnIsmSmK3o5yLJkpiUg_2402656ae54246e880715f135341f5f7_20200317.csv");
  return 0;
  }