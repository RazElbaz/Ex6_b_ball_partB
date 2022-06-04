#include "Schedule.hpp"

namespace ariel {
    Schedule::Schedule(League &other):Round(1) {
        this->Tournament = other.getTeams();
        for (size_t i = 1; i < GroupSize_max; i++) {
            cout << "Round: " << this->Round++ << endl;
            for (size_t j = 0; j < GroupSize_max / 2; j++) {
                cout << this->Tournament.at(j).name() << "\t";
            }
            cout << "\n" << endl;
            for (size_t k = GroupSize_max - 1; k >= (GroupSize_max / 2); k--) {
                cout << this->Tournament.at(k).name() << "\t";
            }
            cout << "\n" << endl;
            Team tmp = this->Tournament.at(GroupSize_max - 1);
            for (size_t j = GroupSize_max - 1; j > 0; j--) {
                this->Tournament.at(j) = this->Tournament.at(j - 1);
            }
            this->Tournament.at(1) = tmp;
        }
    }

    int Schedule::getRound() const { return this->Round; }
};

