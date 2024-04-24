#pragma once

#include "order_book.h"
#include <vector>

class csv
{
    public:
        static std::vector<order_book> read_csv(std::string csv_filename);

    private:
        static std::vector<std::string> tokenise(std::string csv_line, char separator);
        static order_book strings_to_order_book(std::vector<std::string> tokens);
};