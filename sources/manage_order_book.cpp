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

    for (order_book& order : orders_)
    {
        if
        (
            order.order_type == type
            && order.product == product
            && order.timestamp == timestamp
        )
        {
            orders.push_back(order);
        };
    };

    return orders;
};

double manage_order_book::get_high_price(std::vector<order_book>& orders)
{
    double max = orders[0].price;

    for (order_book& o : orders)
    {
        if (o.price > max)
        {
            max = o.price;
        };
    };

    return max;
};

double manage_order_book::get_low_price(std::vector<order_book>& orders)
{
    double min = orders[0].price;

    for (order_book& o : orders)
    {
        if (o.price < min)
        {
            min = o.price;
        };
    };

    return min;
};

std::string manage_order_book::get_earliest_time()
{
    return orders_[0].timestamp;
};

std::string manage_order_book::get_next_time(std::string timestamp)
{
    std::string next_time;
    for (order_book& o : orders_)
    {
        if (o.timestamp > timestamp)
        {
            next_time = o.timestamp;
            break;
        };
    };

    if (next_time == "")
    {
        next_time = orders_[0].timestamp;
    };

    return next_time;
};