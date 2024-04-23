#include <iostream>
#include <string>
#include <vector>

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
    std::vector<std::string> tokens;
    std::string str = "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187308,7.44564869\n2020/03/17 17:01:24.884492,ETH/BTC,bid,0.02187307,3.467434";

    tokens = tokenise(str, ',');

    for (std::string& token : tokens)
    {
        std::cout << token << std::endl;
    }

    return 0;
};