#pragma once

#include <string>

enum class order_book_type{bid, ask};

class order_book
{
    public:
        // custom constructor
        order_book
        (
            const double& new_price,
            const double& new_amount,
            const std::string& new_timestamp,
            const std::string& new_product,
            const order_book_type& new_order_type
        );
    
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        order_book_type order_type;
};