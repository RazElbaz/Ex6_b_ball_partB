#include "vector"
#include <ctime>
#include "cmath"
#include "Team.hpp"
#include "string"
#include <iostream>
using std::vector;
constexpr int MAX = 26;
constexpr int MIN_NameSize = 3;
constexpr double Thousand = 1000.0;
constexpr int GroupSize_max=20;
using namespace std;

namespace ariel{
    class League {
    private:
        vector<Team> Teams;
        static Team CreateRandomTeam();
        static string RandomString(int n);
    public:
        League();
        League(vector<Team>& teams);
        vector<Team>& getTeams();
    };
}