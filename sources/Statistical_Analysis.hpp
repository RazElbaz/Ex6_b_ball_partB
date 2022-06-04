#include "Schedule.hpp"
#include "Team.hpp"
#include "vector"
#include <iostream>

using namespace std;
namespace ariel{
    class Statistical_Analysis {
    private:
        vector<Team> Teams;
        vector<Game> Games;

    public:
        Statistical_Analysis(vector<Team>& teams,vector<Game>& games);
    };
}