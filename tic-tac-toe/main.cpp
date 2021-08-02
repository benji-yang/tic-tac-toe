#include <iostream>
#include <string>
#include "ttc.hpp"

using namespace std;

int main()
{
    
    welcome();
    for (int i = 1; i < 10  && winning_condition() == false; i++) {

        std::cout << "1 | 2 | 3\n";
        std::cout << "---------\n";
        std::cout << "4 | 5 | 6\n";
        std::cout << "---------\n";
        std::cout << "7 | 8 | 9\n";


        take_turn();
    }

    if (winning_condition() == true) {
        winning_player();
    }

    else {
        std::cout << "It's  a tie.\n";
    }
    return 0;


}