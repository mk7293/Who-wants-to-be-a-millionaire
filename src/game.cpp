//
// Created by Abdul Hakim on 3/28/18.
//

#include <iostream>
#include <sstream>
#include "game.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

std::map<std::string, std::string> Game::questions_;
std::map<std::string, std::string> Game::correct_answers_;
std::vector<std::string> Game::prize_money_;

Game::Game(std::string player) : attempts_(3), prize_won_("0"), player_(player) {}

void Game::initialize_game() {
    questions_ = {
            {"Question 1",  "Option 1, Option 2, Option 3, Option 4"},
            {"Question 2",  "Option 1, Option 2, Option 3, Option 4"},
            {"Question 3",  "Option 1, Option 2, Option 3, Option 4"},
            {"Question 4",  "Option 1,Option 2,Option 3,Option 4"},
            {"Question 5",  "Option 1,Option 2,Option 3,Option 4"},
            {"Question 6",  "Option 1,Option 2,Option 3,Option 4"},
            {"Question 7",  "Option 1,Option 2,Option 3,Option 4"},
            {"Question 8",  "Option 1,Option 2,Option 3,Option 4"},
            {"Question 9",  "Option 1,Option 2,Option 3,Option 4"},
            {"Question 10", "Option 1,Option 2,Option 3,Option 4"}

    };
    correct_answers_ = {
            {"Question 1",  " Option 2"},
            {"Question 2",  "Option 1"},
            {"Question 3",  "Option 1"},
            {"Question 4",  "Option 1"},
            {"Question 5",  "Option 1"},
            {"Question 6",  "Option 1"},
            {"Question 7",  "Option 1"},
            {"Question 8",  "Option 1"},
            {"Question 9",  "Option 1"},
            {"Question 10", "Option 1"}
    };
    prize_money_ = {
            "2,000",
            "4,000",
            "8,000",
            "16,000",
            "32,000",
            "64,000",
            "128,000",
            "250,000",
            "500,000",
            "1,000,000"
    };
}

void Game::play_game() {
    cout << "Welcome " << player_ << endl;
    int question_counter = 0;
    for (auto iter = questions_.begin(); iter != questions_.end(); ++iter) {
        question_counter++;
        string option;
        int answer;
        std::vector<string> options;
        std::istringstream optionStream(iter->second);
        while (std::getline(optionStream, option, ',')) {
            options.push_back(option);
        }
        cout << iter->first << endl;
        cout << iter->second << endl;
        cin >> answer;
        if (cin) {
            if (correct_answers_[iter->first] == options[answer - 1]) {
                cout << "Correct!" << endl;
                prize_won_ = prize_money_[question_counter - 1];
                if (question_counter == 10) {
                    cout << "Congratulations! You are a Millionaire!" << endl;
                    break;
                } else {
                    cout << "Prize Won " << prize_won_ << endl;
                    cout << "Life line remaining : " << attempts_ << endl;
                }
            } else {
                cout << "Wrong!" << endl;
                attempts_--;
                if (attempts_ < 0) {
                    cout << "Game Over!" << endl;
                    if (question_counter > 4 && question_counter <= 7) {
                        prize_won_ = prize_money_[3];
                    } else if (question_counter > 7) {
                        prize_won_ = prize_money_[6];
                    } else {
                        prize_won_ = "0";
                    }
                    cout << "Total prize money won : " << prize_won_ << endl;
                    break;
                }
                cout << "Life line remaining : " << attempts_ << endl;
                iter--;
                question_counter--;
            }
        }
    }

}