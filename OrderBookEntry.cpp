#include "OrderBookEntry.h"
#include <string>
OrderBookEntry::OrderBookEntry(double price, double amount, std::string timestamp, //pentru a intra in contextul
                             std::string product, OrderBookType orderType)          //clasei
    : price(price), amount(amount), timestamp(timestamp), product(product),
      orderType(orderType) {}