#ifndef PLAYER_MANAGEMENT_H
#define PLAYER_MANAGEMENT_H

#include <string>

using namespace std;

class Player {
public:
    int jerseyNumber;
    string name;
    int runs;
    int wickets;
    int matchesPlayed;

    Player();
    void input();
    void display() const;
};

class PlayerManagement {
private:
    int count;
    int capacity;

    void resize();
    
public:
    Player* players;

    PlayerManagement();
    ~PlayerManagement();

    void addPlayer();
    void displayPlayers() const;
    int searchPlayer(const string& name) const;
    int searchPlayerByJersey(int jersey) const;
    void updatePlayer(int index);
    void removePlayer(int index);
    void displayTopScorers(bool byRuns) const;
};

#endif // PLAYER_MANAGEMENT_H
