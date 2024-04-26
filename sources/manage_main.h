#pragma once

#include <vector>
#include "manage_order_book.h"

class manage_main
{
    public:
        // call this to start the sim
        void init();

    private:
        void print_menu();

        void print_help();

        void print_market_stats();

        void enter_offer();

        void enter_bid();

        void print_wallet();

        void go_to_next_time_frame();

        int get_user_option();

        void process_user_option(int user_option);

        std::string current_time_;

        manage_order_book manage_orders_{"C:/Disk/cpp/object_oriented_programming/sources/datasets/data.csv"};
};