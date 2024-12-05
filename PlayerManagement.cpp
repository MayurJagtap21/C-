#include "PlayerManagement.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Player class member function implementations
Player::Player() : jerseyNumber(0), runs(0), wickets(0), matchesPlayed(0) {}

void Player::input() {
    cout << "Enter Jersey Number: ";
    cin >> jerseyNumber;
    cout << "Enter Player Name: ";
    cin.ignore(); // Clear the newline character from the input buffer
    getline(cin, name);
    cout << "Enter Runs: ";
    cin >> runs;
    cout << "Enter Wickets: ";
    cin >> wickets;
    cout << "Enter Matches Played: ";
    cin >> matchesPlayed;
}

void Player::display() const {
    cout << " | " << jerseyNumber << " | " << name << " | " << runs << " | " << wickets << " | " << matchesPlayed << " |\n";
}

// PlayerManagement class member function implementations
PlayerManagement::PlayerManagement() : count(0), capacity(5) {
    players = new Player[capacity];
}

PlayerManagement::~PlayerManagement() {
    delete[] players;
}

void PlayerManagement::resize() {
    capacity *= 2;
    Player* newPlayers = new Player[capacity];
    for (int i = 0; i < count; i++) {
        newPlayers[i] = players[i];
    }
    delete[] players;
    players = newPlayers;
}

void PlayerManagement::addPlayer() {
    if (count >= capacity) {
        resize();
    }
    players[count].input();
    count++;
}

void PlayerManagement::displayPlayers() const {
    cout << "-------------------------------------------------------------------\n";
    cout << "| Jersey Number | Name          | Runs | Wickets | Matches Played |\n";
    cout << "-------------------------------------------------------------------\n";
    for (int i = 0; i < count; i++) {
        players[i].display();
    }
    cout << "-------------------------------------------------------------------\n";
}

int PlayerManagement::searchPlayer(const string& name) const {
    for (int i = 0; i < count; i++) {
        if (players[i].name == name) {
            return i; // return index
        }
    }
    return -1; // not found
}

int PlayerManagement::searchPlayerByJersey(int jersey) const {
    for (int i = 0; i < count; i++) {
        if (players[i].jerseyNumber == jersey) {
            return i; // return index
        }
    }
    return -1; // not found
}

void PlayerManagement::updatePlayer(int index) {
    if (index >= 0 && index < count) {
        cout << "Updating details for " << players[index].name << ": \n";
        cout << "Enter new Runs: ";
        cin >> players[index].runs;
        cout << "Enter new Wickets: ";
        cin >> players[index].wickets;
        cout << "Enter new Matches Played: ";
        cin >> players[index].matchesPlayed;
        cout << "Updated details for " << players[index].name << ": \n";
        players[index].display();
    }
}

void PlayerManagement::removePlayer(int index) {
    if (index >= 0 && index < count) {
        for (int i = index; i < count - 1; i++) {
            players[i] = players[i + 1];
        }
        count--;
        cout << "Player removed from database\n";
    }
}

void PlayerManagement::displayTopScorers(bool byRuns) const {
    Player* sortedPlayers = new Player[count];
    for (int i = 0; i < count; i++) {
        sortedPlayers[i] = players[i];
    }

    // Simple bubble sort or you can use std::sort for better performance
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if ((byRuns && sortedPlayers[j].runs < sortedPlayers[j + 1].runs) ||
                (!byRuns && sortedPlayers[j].wickets < sortedPlayers[j + 1].wickets)) {
                swap(sortedPlayers[j], sortedPlayers[j + 1]);
            }
        }
    }

    cout << (byRuns ? "Top Three Run Scorers:\n" : "Top Three Wicket Takers:\n");
    for (int i = 0; i < min(3, count); i++) {
        sortedPlayers[i].display();
    }

    delete[] sortedPlayers;
}
