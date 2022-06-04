#include "Team.hpp"
#include "iostream"
using namespace ariel;
Team::Team(std::string &name, double talent_level) {
    if(talent_level<minLevel||talent_level>maxLevel){
        throw ("A class representing a group. Each group has a unique name and level of talent represented by a number (between 0 and 1)");
    }
    Name=name;
    TalentLevel=talent_level;
    this->In_score=0;
    this->Out_score=0;
    this->Win=0;
    this->Loss=0;
    this->AbsorbentPoints=0;
}
string Team::name() const{
    return this->Name;
}
double Team::talentLevel() const {
    return this->TalentLevel;
}
int Team::getIn_score()const {return this->In_score;}
int Team::getOut_score()const {return this->Out_score;}
int Team::getAbsorbentPoints() const {return this->AbsorbentPoints;}
int Team::getLoss() const {return this->Loss;}
int Team::getWin() const {return this->Win;}
void Team::setIn_score(int in) { this->In_score=in;}
void Team::setOut_score(int out) {this->Out_score=out;}
void Team::setLoss() {this->Loss++;}
void Team::setWin() {this->Win++;}
void Team::setAbsorbentPoints(int points) {this->AbsorbentPoints+=points;}