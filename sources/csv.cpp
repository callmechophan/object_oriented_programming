#include "csv.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

std::vector<order_book> csv::read_csv(std::string csv_filename)
{
    std::vector<order_book> orders;

    std::ifstream csv_file{csv_filename};
    std::string line;

    if (csv_file.is_open())
    {
        while (std::getline(csv_file, line))
        {
            try
            {
                orders.push_back(strings_to_order_book(tokenise(line, ',')));
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            };
        };

        csv_file.close();
    };

    return orders;
};

std::vector<std::string> csv::tokenise(std::string csv_line, char separator)
{
    std::vector<std::string> tokens; // stores the token
    std::string token;

    /*
    identity the position of the token
        - start: start with 0, when access loop end + 1
        - end: from start to seperator
    */
    signed int start, end;

    start = 0;
    
    if (start != csv_line.size())
    {
        do
        {
            end = csv_line.find_first_of(separator, start);

            if (end >= 0)
            {
                token = csv_line.substr(start, end - start);
            }
            else // when access else, not found separator, end = -1
            {
                token = csv_line.substr(start, csv_line.size() - start);
            };

            tokens.push_back(token); // save the token

            /*
            modify start

            EX: "ETH/BTC,bid"
                - start = 0
                - end = 7
                - start = 7 + 1 = 8 // new position modify
            */
            start = end + 1;
        }
        while(end > 0); // continue loop condition
    };

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