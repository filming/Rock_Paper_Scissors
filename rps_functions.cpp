#include <iostream>
#include <string>
#include <ctype.h>
#include <time.h>
#include "rps_functions.hpp"

bool is_numeric(std::string& raw_user_input){
    for (const char& letter : raw_user_input){
        if (!isdigit(letter)){return false;}
    }
    return true;
}

int get_user_choice(){
    while (true){
        std::string raw_user_input = "";

        std::cout << "Choose an option below!\n1) Rock\n2) Paper\n3) Scissors\nChoice: ";
        std::cin >> raw_user_input;
        std::cout << "\n";

        if (is_numeric(raw_user_input)){
            int user_input = std::stoi(raw_user_input);

            if (1 <= user_input && user_input <= 3){
                return user_input;
            }    
        }
    }
}

std::string choice_str(const int& choice){
    switch(choice){
        case 1:
            return "rock";
        case 2:
            return "paper";
        case 3:
            return "scissors";
    };

    return "invalid";
}

void game_status(const std::string& user_choice_str, const std::string& computer_choice_str){
    std::string result;
    
    // finding game end result
    if (user_choice_str == computer_choice_str){
        result = "draw";
    }

    else if (user_choice_str == "rock"){
        if (computer_choice_str == "paper"){
            result = "computer";
        } else {
            result = "user";
        }
    }

    else if (user_choice_str == "paper"){
        if (computer_choice_str == "scissors"){
            result = "computer";
        } else {
            result = "user";
        }
    }

    else if (user_choice_str == "scissors"){
        if (computer_choice_str == "rock"){
            result = "computer";
        } else {
            result = "user";
        }
    }

    // displaying game end result
    if (result == "user"){
        std::cout << "You have won! The computer chose " << computer_choice_str << "!\n";
    } else if (result == "computer"){
        std::cout << "You have lost! The computer chose " << computer_choice_str << "!\n";
    } else {
        std::cout << "It is a tie! The computer also chose " << computer_choice_str << "!\n";
    }
}