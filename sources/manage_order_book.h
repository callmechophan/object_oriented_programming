#pragma once

#include "order_book.h"
#include "csv.h"
#include <string>
#include <vector>

class manage_order_book
{
    public:
        /**reading a csv data file*/
        manage_order_book(std::string csv_filename);
        
        /**return vector of all know products in the datasets*/
        std::vector<std::string> get_known_products();

        /**return vector of orders according to the send filters*/
        std::vector<order_book> get_orders(order_book_type type, std::string product, std::string timestamp);
};