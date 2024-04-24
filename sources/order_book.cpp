#include "order_book.h"

order_book::order_book
(
    const double& new_price,
    const double& new_amount,
    const std::string& new_timestamp,
    const std::string& new_product,
    const order_book_type& new_order_type
)
:   price(new_price),
    amount(new_amount),
    timestamp(new_timestamp),
    product(new_product),
    order_type(new_order_type)
{}; // constructor initialisation list

order_book_type order_book::strings_to_order_book_type(const std::string& order_book_type_str)
{
    if (order_book_type_str == "bid")
    {
        return order_book_type::bid;
    }
    else if (order_book_type_str == "bid")
    {
        return order_book_type::ask;
    }
    else
    {
        return order_book_type::unknown;
    };
};