#include "Team.hpp"
#include "ctime"
#include "stdexcept"
constexpr int bonus=10;
constexpr int Result_min=50;
constexpr  int Result_home_min=55;
constexpr int Result_max=101;
using namespace std;
namespace ariel{
    class Game{
    private:
        Team In, Out;
        int In_score, Out_score;

    public:
        Game(Team &in, Team &out);
        void GameResult();
        Team &Win();
        void setIn_score(int in);
        void setOut_score(int out);
    };
}