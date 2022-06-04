#include "Leauge.hpp"
#include "array"

using namespace ariel;
League::League() {
    srand(time(0));
    for (int i = 0; i < GroupSize_max; ++i) {
        Team randomTeam = CreateRandomTeam();
        this->Teams.push_back(randomTeam);


    }
}
League::League(vector<Team>& given_teams) {
    if (given_teams.size() == GroupSize_max) {
        for (const Team &t: given_teams) {
            this->Teams.push_back(t);
        }

    } else if(given_teams.size() < GroupSize_max){
        for (const Team &t: given_teams) {
            this->Teams.push_back(t);
        }
        for (int i = 0; i < (MAX-given_teams.size()-1); ++i) {
            Team randomTeam=CreateRandomTeam();
            this->Teams.push_back(randomTeam);
        }
    } else{
        throw "Team size in the league is a maximum of 20";
    }
}

string League:: RandomString(int n) {
    array<char,MAX> alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z' };
    string str;
    for (int i = 0; i < n; i++) { str+= alphabet.at(rand()%MAX);}
    return str;
}
Team League::CreateRandomTeam() {
    //create random name with random length between 3 and 7
    string randomName=RandomString(MIN_NameSize + (rand() % (MIN_NameSize+1)));
    //create random talent Level between 0 and 1 for creating new team
    double random_talentLevel = round(((double)rand() / RAND_MAX) * Thousand) / Thousand;
    Team randomTeam{randomName, random_talentLevel};
    return randomTeam;
}
vector <Team> &League::getTeams() { return this->Teams;}
