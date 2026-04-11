#include "MerkelMain.h"
#include <iostream>
#include <map>
#include <vector>
#include <cfloat>
#include <climits>
#include "CSVReader.h"
MerkelMain::MerkelMain() {
}
void MerkelMain::init() {
    loadOrderBook();
    int input;
    while (true){
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}
double MerkelMain::computeAveragePrice(const std::vector<OrderBookEntry> &entries) {
  if (entries.empty()) {
    return 0.0;
  }

  double average = 0.0;
  for (const auto &entry : entries) {
    average += entry.price;
  }
  double size = entries.size();
  return average / size;
}
double MerkelMain::computeLowPrice(const std::vector<OrderBookEntry> &entries) {
  if (entries.empty()) {
    return 0.0;
  }
  double minPrice = DBL_MAX;
  for (const auto &entry : entries) {
    if (entry.price < minPrice)
      minPrice = entry.price;
  }
  return minPrice;
}
double MerkelMain::computeHighPrice(const std::vector<OrderBookEntry> &entries) {
  if (entries.empty()) {
    return 0.0;
  }
  double maxPrice = DBL_MIN;
  for (const auto &entry : entries) {
    if (entry.price > maxPrice)
      maxPrice = entry.price;
  }
  return maxPrice;
}
double MerkelMain::computePriceSpread(const std::vector<OrderBookEntry> &entries) {
  if (entries.empty()) {
    return 0.0;
  }
  double lowPrice = MerkelMain::computeLowPrice(entries);
  double highPrice = MerkelMain::computeHighPrice(entries);
  return highPrice - lowPrice;
}
void MerkelMain::printMenu() {
  std::cout << "1. Print help" << std::endl;
  std::cout << "2. Print exchange stats" << std::endl;
  std::cout << "3. Plance an ask" << std::endl;
  std::cout << "4. Place a bid" << std::endl;
  std::cout << "5. Print wallet" << std::endl;
  std::cout << "6. Continue" << std::endl;
}
int MerkelMain::getUserOption() {
  int userOptions;
  std::cin >> userOptions;
  return userOptions;
}
void MerkelMain::printHelp() {
  std::cout << "Help - choose options from the menu" << std::endl;
  std::cout << "and follow the instructions" << std::endl;
}
void MerkelMain::printMarketStats() {
  std::cout << "OrderBook contains: " << orders.size() <<" entries" <<std::endl;
  unsigned int bids = 0;
  unsigned int asks = 0;
  for(OrderBookEntry &e : orders){
    if(e.orderType == OrderBookType::ask){
      asks++;
    }
    if(e.orderType == OrderBookType::bid){
      bids++;
    }
  }
  std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl;
}
void MerkelMain::enterAsk() {
  std::cout << "Place an ask - here you can place an ask order" << std::endl;
}
void MerkelMain::enterBid() {
  std::cout << "Place a bid - here you can place a bid order" << std::endl;
}
void MerkelMain::printWallet() {
  std::cout << "Print wallet - here you can see your current wallet balance"
            << std::endl;
}
void MerkelMain::gotoNextTimeframe() {
  std::cout << "Continue - here you can continue to the next step" << std::endl;
}
void MerkelMain::processUserOption(int option) {
    switch (option) {
    case 1:
        printHelp();
        break;
    case 2:
        printMarketStats();
        break;
    case 3:
        enterAsk();
        break;
    case 4:
        enterBid();
        break;
    case 5:
        printWallet();
        break;
    case 6:
        gotoNextTimeframe();
        break;
    default:
        std::cout << "Invalid option. Please try again." << std::endl;
        break;
    }
}
std::map<int, void (MerkelMain::*)()> MerkelMain::initMenu() {
  std::map<int, void (MerkelMain::*)()> menuOptions;
  menuOptions[1] = &MerkelMain::printHelp;
  menuOptions[2] = &MerkelMain::printMarketStats;
  menuOptions[3] = &MerkelMain::enterAsk;
  menuOptions[4] = &MerkelMain::enterBid;
  menuOptions[5] = &MerkelMain::printWallet;
  menuOptions[6] = &MerkelMain::gotoNextTimeframe;
  return menuOptions;
}
void MerkelMain::loadOrderBook() {
   orders = CSVReader::readCSV("1XejnIsmSmK3o5yLJkpiUg_2402656ae54246e880715f135341f5f7_20200317.csv");
}