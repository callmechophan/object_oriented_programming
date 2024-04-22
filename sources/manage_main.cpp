#include <iostream>
#include "manage_main.h"

void manage_main::init()
{
    load_order_book();
    
    int user_option;

    while (true)
    {
        print_menu();
        user_option = get_user_option();

        process_user_option(user_option);
    };
};

void manage_main::load_order_book()
{
    orders.push_back(order_book{7.44564869, 0.02187308, "2020/03/17 17:01:24.884492", "ETH/BTC", order_book_type::bid});
    orders.push_back(order_book{3.467434, 0.02187307, "2020/03/17 17:01:24.884492", "ETH/BTC", order_book_type::bid});
}

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
};

void manage_main::print_help()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers " << std::endl;
};

void manage_main::print_market_stats()
{
    std::cout << "OrderBook contains: " << orders.size() << std::endl;
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