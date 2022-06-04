#include "Schedule.hpp"

namespace ariel {
    Schedule::Schedule(League &other):Round(1) {
        this->Tournament = other.getTeams();
        vector<Team> group1;
        vector<Team> group2;
        size_t counterGame=0;
        for (size_t i = 1; i < GroupSize_max; i++) {
            cout << "Round: " << this->Round++ << endl;
            for (size_t j = 0; j < GroupSize_max / 2; j++) {
                cout << this->Tournament.at(j).name() << "\t";
                group1.push_back(Tournament.at(j));
            }
            cout << "\n" << endl;
            for (size_t k = GroupSize_max - 1; k >= (GroupSize_max / 2); k--) {
                cout << this->Tournament.at(k).name() << "\t";
                group2.push_back(Tournament.at(k));
            }
            cout << "\n" << endl;
            Team tmp = this->Tournament.at(GroupSize_max - 1);
            for (size_t j = GroupSize_max - 1; j > 0; j--) {
                this->Tournament.at(j) = this->Tournament.at(j - 1);
            }
            this->Tournament.at(1) = tmp;

        }
        for (size_t i = 0; i <group1.size() ; ++i) {
            Game current {group1.at(counterGame), group2.at(counterGame)};
            current.GameResult();
            counterGame++;
            this->games.push_back(current);
        }
    }

    int Schedule::getRound() const { return this->Round; }

    vector<Game> Schedule::getGames() const { return this->games;}
};

