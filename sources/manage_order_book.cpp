#include "manage_order_book.h"
#include <string>
#include <vector>
#include "csv.h"
#include <map>

manage_order_book::manage_order_book(std::string csv_filename)
{
    orders_ = csv::read_csv(csv_filename);
};
        
std::vector<std::string> manage_order_book::get_known_products()
{
    std::vector<std::string> products;

    /**store unique product*/
    std::map<std::string, bool> product_map;

    for (order_book& order : orders_)
    {
        product_map[order.product] = true;
    };

    // push product from "product_map" to vector "products"
    for (const auto& p : product_map)
    {
        products.push_back(p.first);
    };

    return products;
};

std::vector<order_book> manage_order_book::get_orders(order_book_type type, std::string product, std::string timestamp)
{
    std::vector<order_book> orders;

    return orders;
};