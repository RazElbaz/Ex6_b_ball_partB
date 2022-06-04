#include "Statistical_Analysis.hpp"

using namespace ariel;

Statistical_Analysis::Statistical_Analysis(League league1, Schedule schedule1):league(std::move(league1)), schedule(std::move(schedule1)){
    /***
     * Who are the leading teams in the league (the number of teams you return will be according to a parameter you will receive from outside)
     */
    for (size_t i = 0; i < league.getTeams().size(); ++i) {
        Teams_win.push_back(league.getTeams().at(i));
        SlimDifference.push_back(league.getTeams().at(i));
    }
    //sort the teams by wins
    sort(Teams_win.end(), Teams_win.end(), [](Team const &one, Team const &two){
        return (one.getWin()/one.getLoss())<(two.getWin()/two.getLoss());
    });
    //sort the teams by Slim Difference
    sort(SlimDifference.begin(), SlimDifference.end(), [](Team const &one, Team  const &two){
        return ((one.getOut_score()+one.getIn_score())-one.getAbsorbentPoints()) < ((two.getOut_score()+two.getIn_score())- two.getAbsorbentPoints());
    });
}

vector<Team> Statistical_Analysis::getSlimDifference() {
    /***
     * Slim difference (points scored by a team less points scored by a team)
     */
    return SlimDifference;
}

vector<Team> Statistical_Analysis::getTeam_win() {
    /***
     * Ratio of wins and losses
     */
    return  Teams_win;
}

vector<Team > Statistical_Analysis::getTheLeadingGroups(int number) {
    /***
     * Who are the leading teams in the league (the number of teams you return will be according to a parameter you will receive from outside)
     */
    vector<Team>LeadingGroups(this->Teams_win.begin(), this->Teams_win.begin()+number);
    return LeadingGroups;
}

int Statistical_Analysis::SequenceOfVictories() {
    /***
     * What was the length of the longest winning streak of the season
     */
    vector<Team> Teams = this->league.getTeams();
    vector<Game> Games = this->schedule.getGames();
    int Sequence = 0;
    int current=0;
    for(unsigned int i=0; i< Teams.size(); ++i){
        Team curr = Teams.at(i);
        current = 0;
        for(unsigned int j = 0; j<Games.size(); ++j){
            if(Teams.at(i) == Games.at(i).Win()) { current++; }
            else{current=0;}
            if(current > Sequence){Sequence = current;}
        }}
    return Sequence;
}

int Statistical_Analysis::SequenceOfLosses() {
    /***
     * What was the length of the longest losing streak in the season
     */
    vector<Team> Teams = this->league.getTeams();
    vector<Game> Games = this->schedule.getGames();
    int Sequence = 0;
    int current=0;
    for(unsigned int i=0; i< Teams.size(); ++i){
        Team curr = Teams.at(i);
        current = 0;
        for(unsigned int j = 0; j<Games.size(); ++j){
            if(Teams.at(i) != Games.at(i).Win()) { current++; }
            else{current=0;}
            if(current > Sequence){Sequence = current;}
        }}
    return Sequence;
}
int Statistical_Analysis::ScoredMore(){
    int answer =0;
    for (size_t i = 0; i < this->league.getTeams().size(); ++i) {
        if((this->league.getTeams().at(i).Out_score+this->league.getTeams().at(i).In_score)>this->league.getTeams().at(i).AbsorbentPoints){
            answer++;
        }}
    return answer;
}
///////////////////////my 2 new statistic////////////////////////
int Statistical_Analysis::difference(size_t game) {
    /***
     * The difference between the number of points of the game
     */
    if(this->schedule.getGames().at(game).In_score-this->schedule.getGames().at(game).Out_score>0){
        return this->schedule.getGames().at(game).In_score-this->schedule.getGames().at(game).Out_score;
    }
    return -(this->schedule.getGames().at(game).In_score-this->schedule.getGames().at(game).Out_score);
}
vector<Team > Statistical_Analysis::getTheLosingGroups(int number) {
    /***
     * Who are the losing teams in the league (the number of teams you return will be according to a parameter you will receive from outside)
     */
    vector<Team>LosingGroups(this->Teams_win.end()-number, this->Teams_win.end());
    return LosingGroups;
}