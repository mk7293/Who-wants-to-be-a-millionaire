//
// Created by Abdul Hakim on 3/28/18.
//

#ifndef MILLIONAIREGAME_GAME_H
#define MILLIONAIREGAME_GAME_H


#include <string>
#include <vector>
#include <map>

class Game {
public:
    Game(std::string player);
    void play_game();
    static void initialize_game();

private:
    int attempts_;
    std::string prize_won_;
    std::string player_;
    static std::map<std::string, std::string> questions_;
    static std::map<std::string, std::string> correct_answers_;
    static std::vector<std::string> prize_money_;

};


#endif //MILLIONAIREGAME_GAME_H
