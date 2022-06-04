#include "Schedule.hpp"
#include "Team.hpp"
#include "vector"
#include <iostream>
#include "algorithm"

using namespace std;
namespace ariel {
    class Statistical_Analysis {
        League league;
        Schedule schedule;
        vector<Team> Teams_win;//Ratio of wins and losses
        vector<Team> SlimDifference; //Slim difference (points scored by a team less points scored by a team

    public:
        Statistical_Analysis(League league1, Schedule schedule1);
        vector <Team> getTheLeadingGroups(int number);
        vector<Team> getTeam_win();
        vector<Team> getSlimDifference();
        int SequenceOfVictories();
        int SequenceOfLosses();
        int ScoredMore();
        int difference(size_t game);//The difference between the number of points of the game
        vector <Team> getTheLosingGroups(int number);

    };
};