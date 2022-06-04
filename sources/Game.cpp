#include "Game.hpp"

using namespace ariel;
Game::Game(Team &in, Team &out): In(in), Out(out) ,Out_score(0),In_score(0){}
void Game::GameResult() {
    srand(time(0));
    int OutRandomScore = Result_min + (rand() % Result_max);
    int InRandomScore = Result_home_min + (rand() % Result_max);
    In_score = InRandomScore;
    Out_score = OutRandomScore;
    if (In.talentLevel() > Out.talentLevel()) {
        In_score += bonus;
    } else {
        Out_score += bonus;
    }
}

Team& Game::Win() {
    if(In_score<=0 || Out_score<=0){
        throw ("There is no winner yet");
    }
    if (In_score>Out_score){ return In;}
    return Out;
}

void Game::setIn_score(int in) { this->In_score=in;}
void Game::setOut_score(int out) {this->Out_score=out;}