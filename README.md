# Crypto Trading Platform

A basic C++ program that reads and processes cryptocurrency order book data from a CSV file.

## Project Structure

- main.cpp: Entry point for the application.
- MerkelMain.cpp / .h: Core application logic and user interface.
- OrderBookEntry.cpp / .h: Class representing a single trade or order record.
- CSVReader.cpp / .h: Reads CSV rows and converts them into order book entries.
- 1XejnIsmSmK3o5yLJkpiUg_2402656ae54246e880715f135341f5f7_20200317.csv: Historical order book data used by the program.

## Compilation

To compile the project from the terminal using g++, run:

g++ main.cpp MerkelMain.cpp OrderBookEntry.cpp CSVReader.cpp -o crypto_app

## Running

After compiling, you can run the executable:

./crypto_app

## CSV Notes

- The reader loads valid rows and ignores bad or empty lines.
- If the CSV has blank lines, you may see skip messages while loading.
