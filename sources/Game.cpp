#include "Game.hpp"
#include "iostream"
using namespace ariel;
Game::Game(Team &in, Team &out): In(in), Out(out) ,Out_score(0),In_score(0){}
void Game::GameResult() {
    srand(time(0));
    int OutRandomScore = Result_min + (rand() % Result_min);
    int InRandomScore =Result_home_min + (rand() % Result_max);
    setIn_score(InRandomScore);
    this->Out_score=OutRandomScore;
    if (In.talentLevel() > Out.talentLevel()) {
        In_score += bonus;
        this->In.setIn_score(In_score);
    } else {
        Out_score += bonus;
        this->Out.setOut_score(Out_score);
    }
    this->In.setAbsorbentPoints(Out_score);
    this->Out.setAbsorbentPoints(In_score);
}

Team Game::Win() {
    if(this->In_score<=0 || this->Out_score<=0){
        throw ("There is no winner yet");
    }
    if (this->In_score>this->Out_score){
        this->In.setWin();
        this->Out.setLoss();
        return In;
    }
    this->Out.setWin();
    this->In.setLoss();
    return Out;
}
void Game::setIn_score(int in) {
    this->In_score=in;
}
void Game::setOut_score(int out) {
    this->Out_score=out;
}