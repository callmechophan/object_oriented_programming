#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> tokenise(std::string csv_line, char separator)
{
    std::vector<std::string> tokens; // stores the token
    std::string token;

    /*
    identity the position of the token
        - start: start with 0, when access loop end + 1
        - end: from start to seperator
    */
    signed int start, end;

    start = 0;
    
    if (start != csv_line.size())
    {
        do
        {
            end = csv_line.find_first_of(separator, start);

            if (end >= 0)
            {
                token = csv_line.substr(start, end - start);
            }
            else // when access else, not found separator, end = -1
            {
                token = csv_line.substr(start, csv_line.size() - start);
            };

            tokens.push_back(token); // save the token

            /*
            modify start

            EX: "ETH/BTC,bid"
                - start = 0
                - end = 7
                - start = 7 + 1 = 8 // new position modify
            */
            start = end + 1;
        }
        while(end > 0); // continue loop condition
    };

    return tokens;
};

int main()
{
    std::ifstream csv_file{"C:/Disk/cpp/object_oriented_programming/sources/datasets/data.csv"};
    std::string line;
    std::vector<std::string> tokens;

    if (csv_file.is_open())
    {
        std::cout << "File open " << std::endl;

        while (std::getline(csv_file, line))
        {
            std::cout << "Read line: " << line << std::endl;

            tokens = tokenise(line, ','); // current tokens is a line, maximum size is 5, each element in token as value of attribute

            if (tokens.size() != 5) // bad
            {
                std::cout << "Bad line " << std::endl;
                continue;
            };

            try
            {
                // std::stod convert a string into a double
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout << price << ":" << amount << std::endl;
            }
            catch(std::exception& e)
            {
                std::cout << "Bad float! " << tokens[3] << std::endl;
                std::cout << "Bad float! " << tokens[4] << std::endl;
                break;
            };

            // for (std::string& token : tokens)
            // {
            //     std::cout << token << std::endl;
            // };
        };

        csv_file.close();
    }
    else
    {
        std::cout << "File not open. Re-check " << std::endl;
    };

    return 0;
};