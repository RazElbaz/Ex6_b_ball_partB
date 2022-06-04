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
        Team(string &name, double talent_level);
        string name() const;
        double talentLevel() const;
    };
}