#include "Leauge.hpp"
#include "Game.hpp"
#include "vector"
#pragma once
constexpr int six=6;
namespace ariel{
    class Schedule{
    private:
        int Round;
        vector<Team> Tournament;
        vector<Game> games;
    public:
        Schedule(League &other);
        int getRound() const;
        vector<Game> getGames()const;
    };
}

