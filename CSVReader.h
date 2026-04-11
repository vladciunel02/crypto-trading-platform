#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>
class CSVReader {
    public:
    CSVReader();
    static std::vector<OrderBookEntry> readCSV(std::string filename);
    private:
    static std::vector<std::string> tokenise(std::string line, char separator);
    static OrderBookEntry stringToOrderBookEntry(std::vector<std::string> tokens);
};