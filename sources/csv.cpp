#include "csv.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

std::vector<order_book> csv::read_csv(std::string csv_filename)
{
    std::vector<order_book> orders;

    return orders;
};

std::vector<std::string> csv::tokenise(std::string csv_line, char separator)
{
    std::vector<std::string> tokens;

    return tokens;
};

order_book csv::strings_to_order_book(std::vector<std::string> tokens)
{
    double price, amount;

    if (tokens.size() != 5) // bad
    {
        std::cout << "Bad! " << std::endl;
        
        throw std::exception{};
    };

    try
    {
        // std::stod convert a string into a double
        double price = std::stod(tokens[3]);
        double amount = std::stod(tokens[4]);
        std::cout << price << ":" << amount << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Bad price! " << tokens[3] << std::endl;
        std::cout << "Bad amount! " << tokens[4] << std::endl;
        throw;
    };

    order_book order{price, amount, tokens[0], tokens[1], order_book::strings_to_order_book_type(tokens[2])};

    return order;
};