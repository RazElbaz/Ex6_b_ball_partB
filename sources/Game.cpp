#include "Game.hpp"

using namespace ariel;
Game::Game(Team &in, Team &out): In(in), Out(out) ,Out_score(0),In_score(0){}
void Game::GameResult() {
    /**
     * Add points and bonuses according to the instructions of the task.
     * Update the points of each group
     */
    srand(time(0));//The  rand()  function returns a pseudo-random integer in the range 0 to RAND_MAX inclusive
    int OutRandomScore = Result_min + (rand() % Result_min);
    int InRandomScore =Result_home_min + (rand() % Result_max);
    //set scores
    setIn_score(InRandomScore);
    setOut_score(OutRandomScore);
    //adding bonus
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
    /**
     * return the winner of the game
     */
    if(this->In_score<=0 || this->Out_score<=0){
        throw ("There is no winner yet");
    }
    //checking who is the winner
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