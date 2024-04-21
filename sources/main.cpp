#include <iostream>

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
        std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers " << std::endl;
    }
    else if (user_option == 2)
    {
        std::cout << "Market looks good " << std::endl;
    }
    else if (user_option == 3)
    {
        std::cout << "Mark an offer - enter the amount " << std::endl;
    }
    else if (user_option == 4)
    {
        std::cout << "Mark a bid - enter the amount " << std::endl;
    }
    else if (user_option == 5)
    {
        std::cout << "Your wallet is empty " << std::endl;
    }
    else if (user_option == 6)
    {
        std::cout << "Going to the next time frame " << std::endl;
    };

    std::cout << "\n";
};

int main()
{
    while (true)
    {
        print_menu();

        int user_option = get_user_option();

        process_user_option(user_option);
    };

    return 0;
};