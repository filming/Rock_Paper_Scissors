#include <iostream>
#include <string>
#include <ctype.h>
#include <time.h>
#include "rps_functions.hpp"

int main(){
    std::cout << "Welcome To Rock, Paper, Scissors!\n\n";

    // get user input
    int user_choice = get_user_choice();
    std::string user_choice_str = choice_str(user_choice);

    // get computer choice
    srand(time(NULL));

    int computer_choice = rand() % 3 + 1;
    std::string computer_choice_str = choice_str(computer_choice);

    // displaying the end result
    game_status(user_choice_str, computer_choice_str);
    
}