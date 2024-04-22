#include <iostream>
#include <string>
#include <vector>

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
        )
        :   price(new_price),
            amount(new_amount),
            timestamp(new_timestamp),
            product(new_product),
            order_type(new_order_type)
        {}; // constructor initialisation list

        double price;
        double amount;
        std::string timestamp;
        std::string product;
        order_book_type order_type;
};

void print_menu()
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
    std::cout << "Type in 1-6: ";
};

void print_help()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers " << std::endl;
};

void print_market_stats()
{
    std::cout << "Market looks good " << std::endl;
};

void enter_offer()
{
    std::cout << "Mark an offer - enter the amount " << std::endl;
};

void enter_bid()
{
    std::cout << "Mark a bid - enter the amount " << std::endl;
};

void print_wallet()
{
    std::cout << "Your wallet is empty " << std::endl;
};

void go_to_next_time_frame()
{
    std::cout << "Going to the next time frame " << std::endl;
};

int get_user_option()
{
    int user_option;
    std::cin >> user_option;
    std::cout << "You chose: " << user_option << std::endl;

    return user_option;
};

void process_user_option(int user_option)
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

int main()
{
    // vector of objects
    std::vector<order_book> o;

    // push directly
    o.push_back(order_book{7.44564869, 0.02187308, "2020/03/17 17:01:24.884492", "ETH/BTC", order_book_type::bid});
    o.push_back(order_book{3.467434, 0.02187307, "2020/03/17 17:01:24.884492", "ETH/BTC", order_book_type::bid});

    std::cout << "price: " << o[1].price << std::endl;

    // while (true)
    // {
    //     print_menu();

    //     int user_option = get_user_option();

    //     process_user_option(user_option);
    // };

    return 0;
};