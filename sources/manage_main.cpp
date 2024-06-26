#include <iostream>
#include "manage_main.h"
#include "csv.h"

void manage_main::init()
{
    current_time_ = manage_orders_.get_earliest_time();
    int user_option;

    while (true)
    {
        print_menu();
        user_option = get_user_option();

        process_user_option(user_option);
    };
};

void manage_main::print_menu()
{
    std::cout << "Choose an option: " << std::endl;
    // 1 print help
    std::cout << "1. Print help " << std::endl;

    // 2 print exchange stats
    std::cout << "2. Print exchange stats " << std::endl;

    // 3 make an offer
    std::cout << "3. Make an offer " << std::endl;

    // 4 make a bid
    std::cout << "4. Make a bid " << std::endl;

    // 5 print wallet
    std::cout << "5. Print wallet " << std::endl;

    // 6 continue
    std::cout << "6. Continue " << std::endl;
    std::cout << "====================" << std::endl;

    // current time
    std::cout << current_time_ << std::endl;
};

void manage_main::print_help()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers " << std::endl;
};

void manage_main::print_market_stats()
{
    for (const std::string& p : manage_orders_.get_known_products())
    {
        std::cout << "Product: " << p << std::endl;

        std::vector<order_book> order_where = manage_orders_.get_orders(order_book_type::ask, p, current_time_);
        std::cout << "Asks seen: " << order_where.size() << std::endl;
        std::cout << "Max ask: " << manage_order_book::get_high_price(order_where) << std::endl;
        std::cout << "Min ask: " << manage_order_book::get_low_price(order_where) << std::endl;
    };
};

void manage_main::enter_offer()
{
    std::cout << "Mark an offer - enter the amount " << std::endl;
};

void manage_main::enter_bid()
{
    std::cout << "Mark a bid - enter the amount " << std::endl;
};

void manage_main::print_wallet()
{
    std::cout << "Your wallet is empty " << std::endl;
};

void manage_main::go_to_next_time_frame()
{
    std::cout << "Going to the next time frame " << std::endl;
    current_time_ = manage_orders_.get_next_time(current_time_);
};

int manage_main::get_user_option()
{
    int user_option;

    std::cout << "Type in 1-6: ";
    std::cin >> user_option;
    std::cout << "You chose: " << user_option << std::endl;

    return user_option;
};

void manage_main::process_user_option(int user_option)
{
    if (user_option == 0) // bad input
    {
        std::cout << "Invalid choice. Re-type 1-6 " << std::endl;
    }
    else if (user_option == 1)
    {
        print_help();
    }
    else if (user_option == 2)
    {
        print_market_stats();
    }
    else if (user_option == 3)
    {
        enter_offer();
    }
    else if (user_option == 4)
    {
        enter_bid();
    }
    else if (user_option == 5)
    {
        print_wallet();
    }
    else if (user_option == 6)
    {
        go_to_next_time_frame();
    };

    std::cout << "\n";
};