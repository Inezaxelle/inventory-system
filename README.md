# Inventory Management System

This C++ program manages an inventory system that allows users to add items with specific details to a CSV file (`inventory.csv`), list items in alphabetical order, and view command syntaxes.

## Features

- **Add Item**: Adds a new item to the inventory CSV file with details such as item ID, name, quantity, and registration date.
- **List Items**: Displays all items in the inventory CSV file in alphabetical order based on item names.
- **Command Syntax**: Provides users with a list of available commands and their usage.

## Requirements

- C++ compiler with C++11 support (e.g., GCC, Clang)
- MySQL Connector/C++ for database operations (optional for MySQL integration)

## Dependencies

- Standard C++ libraries (`iostream`, `fstream`, `sstream`, `vector`, `algorithm`, etc.)
- MySQL Connector/C++ for MySQL database integration (if using)

## Usage

1. **Compile the Program**: Compile the `main.cpp` file using your preferred C++ compiler. For example:
   ```bash
   g++ -o inventory_management main.cpp -lmysqlcppconn
