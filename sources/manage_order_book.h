#pragma once

#include "order_book.h"
#include "csv.h"
#include <string>
#include <vector>

class manage_order_book
{
    public:
        manage_order_book(std::string csv_filename); // reading a csv data file
        std::vector<std::string> get_known_products(); // return vector of all know products in the datasets
        std::vector<order_book> get_orders(order_book_type type, std::string product, std::string timestamp); // return vector of orders according to the send filters
};