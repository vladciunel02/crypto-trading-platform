#include <string>
#include <vector>
#include <map>
#include "OrderBookEntry.h"
#pragma once
class MerkelMain{
    public:
    MerkelMain();
/** Initialize the application */
void init();
double computeAveragePrice(const std::vector<OrderBookEntry> &entries);
double computeLowPrice(const std::vector<OrderBookEntry> &entries);
double computeHighPrice(const std::vector<OrderBookEntry> &entries);
double computePriceSpread(const std::vector<OrderBookEntry> &entries); 
private:
void printMenu();
void loadOrderBook();
int getUserOption();
void processUserOption(int option);
void printHelp();
void printMarketStats();
void enterAsk();
void enterBid();
void printWallet();
void gotoNextTimeframe();
std::map<int, void (MerkelMain::*)()> initMenu();
std::vector<OrderBookEntry> orders;
};