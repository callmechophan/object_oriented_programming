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