#include <iostream>
#include "PlayerManagement.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{

    PlayerManagement manager;
    while (true) {
        int choice;
        cout << "\nEnter choice:\n";
        cout << "1. Store Players\n2. Display Players\n3. Search Player\n4. Update Data\n5. Remove Player\n6. Leading Scorers\n7. Top Three\n8. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addPlayer();
                break;
            case 2:
                manager.displayPlayers();
                break;
            case 3: {
                string name;
                cout << "Enter Player Name to search: ";
                cin.ignore(); // Clear input buffer
                getline(cin, name);
                int index = manager.searchPlayer(name);
                if (index != -1) {
                    cout << "Player found:\n";
                    manager.players[index].display();
                } else {
                    cout << "Player not found\n";
                }
                break;
            }
            case 4: {
                int jersey;
                cout << "Enter Jersey Number to update: ";
                cin >> jersey;
                int index = manager.searchPlayerByJersey(jersey);
                if (index != -1) {
                    manager.updatePlayer(index);
                } else {
                    cout << "Player not found\n";
                }
                break;
            }
            case 5: {
                int jersey;
                cout << "Enter Jersey Number to remove: ";
                cin >> jersey;
                int index = manager.searchPlayerByJersey(jersey);
                if (index != -1) {
                    manager.removePlayer(index);
                } else {
                    cout << "Player not found\n";
                }
                break;
            }
            case 6: {
                int option;
                cout << "Find leading scorers by:\n1. Runs\n2. Wickets\n";
                cin >> option;
                manager.displayTopScorers(option == 1);
                break;
            }
            case 7: {
                int option;
                cout << "Find top three by:\n1. Runs\n2. Wickets\n";
                cin >> option;
                manager.displayTopScorers(option == 1);
                break;
            }
            case 8:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
	return 0;
}