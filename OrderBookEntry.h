#include <string>
#pragma once
enum class OrderBookType { bid, ask, unknown};

class OrderBookEntry {
public:
  OrderBookEntry(double price, double amount, std::string timestamp,
                 std::string product, OrderBookType orderType);
  static OrderBookType stringToOrderBook(std::string s);
  double price;
  double amount;
  std::string timestamp;
  std::string product;
  OrderBookType orderType;
};