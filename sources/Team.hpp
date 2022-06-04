#include "string"
#pragma once
using namespace std;
constexpr int maxLevel=1;
constexpr int minLevel=0;
namespace ariel{
    class Team{
    private:
        string Name;
        double TalentLevel;
    public:
        int In_score, Out_score;
        int Win, Loss,AbsorbentPoints;
        Team(string &name, double talent_level);
        string name() const;
        double talentLevel() const;
        void setIn_score(int in);
        void setOut_score(int out);
        void setWin();
        void setLoss();
        void setAbsorbentPoints(int points);
        int getIn_score() const;
        int getOut_score()const;
        int getWin()const;
        int getLoss()const;
        int getAbsorbentPoints()const;
        bool operator==(const Team &other) const{
            return this->name()== other.name();
        }
        bool operator!=(const Team &other) const{
            return !(*this == other);
        }
    };
}