#include "Team.hpp"
using namespace ariel;
Team::Team(std::string &name, double talent_level) {
    if(talent_level<minLevel||talent_level>maxLevel){
        throw ("A class representing a group. Each group has a unique name and level of talent represented by a number (between 0 and 1)");
    }
    Name=name;
    TalentLevel=talent_level;
}
string Team::name() const{
    return this->Name;
}
double Team::talentLevel() const {
    return this->TalentLevel;
}