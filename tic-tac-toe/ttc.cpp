#include <iostream>
#include <string>
#include <vector>

int player = 1;
int position = 0;
std::vector<char> choice = {' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' '};
char symbol = ' ';

void welcome() {
    std::cout << "Press [Enter] to begin: ";
    std::cin.ignore();
    std::cout << "\n";
    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "Player 1 will have symbol 'x'\n";
    std::cout << "Player 2 will have symbol 'o'\n";
}

void display_status() {
    std::cout << choice[0] << " | " << choice[1] << " | " << choice[2] << "\n";
    std::cout << "---------\n";
    std::cout << choice[3] << " | " << choice[4] << " | " << choice[5] << "\n";
    std::cout << "---------\n";
    std::cout << choice[6] << " | " << choice[7] << " | " << choice[8] << "\n";
}

void update_symbol() {
    if (player % 2 == 1) {
        choice[position-1] = 'x';
    }

    else {
        choice[position-1] = 'o';
    }
}

void change_player() {
    if (player == 1) {
        player++;
    }

    else {
        player--;
    }
}

void wrong_input() {
    std::cout << "Player " << player << "'s Turn (Enter 1-9): ";
    while (!(std::cin >> position)) {
        std::cout << "Player " << player << ", please enter a valid number between 1 and 9: ";
        std::cin.clear();
        std::cin.ignore();
    }

    std::cout << "\n";

    while (choice[position-1] != ' ') {
        std::cout << "Oops, there's already something in that position!\n\n";
        std::cout << "Player " << player << "'s Turn (Enter 1-9): ";
        std::cin >> position;
        std::cout << "\n";
    }

}
bool winning_condition() {
    if ((choice[0] == choice[1] && choice[1] == choice[2] && choice[0] != ' ') 
    || (choice[3] == choice[4] && choice[4] == choice[5] && choice[3] != ' ') 
    || (choice[6] == choice[7] && choice[7] == choice[8] && choice[6] != ' ') 
    || (choice[0] == choice[3] && choice[3] == choice[6] && choice[0] != ' ') 
    || (choice[1] == choice[4] && choice[4] == choice[7] && choice[1] != ' ') 
    || (choice[2] == choice[5] && choice[5] == choice[8] && choice[2] != ' ') 
    || (choice[0] == choice[4] && choice[4] == choice[8] && choice[0] != ' ')  
    || (choice[2] == choice[4] && choice[4] == choice[6] && choice[2] != ' ')) {
        return true;
    }

    else {
        return false;
    }
}

void take_turn() {
    wrong_input();
    update_symbol();
    change_player();
    display_status();
}

void winning_player() {
    if (player == 1) {
        std::cout << "Player 2 wins.\n";
    }

    if (player == 2) {
        std::cout << "Player 1 wins.\n";
    }
}