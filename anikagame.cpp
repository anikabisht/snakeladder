#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int WINNING_POSITION = 100;

// Snake and ladder positions
int checkSnakesAndLadders(int position) {
    switch(position) {
        case 4: return 14;    // Ladder
        case 9: return 31;    // Ladder
        case 17: return 7;    // Snake
        case 20: return 38;   // Ladder
        case 28: return 84;   // Ladder
        case 40: return 59;   // Ladder
        case 51: return 67;   // Ladder
        case 54: return 34;   // Snake
        case 62: return 19;   // Snake
        case 63: return 81;   // Ladder
        case 64: return 60;   // Snake
        case 71: return 91;   // Ladder
        case 87: return 24;   // Snake
        case 93: return 73;   // Snake
        case 95: return 75;   // Snake
        case 99: return 78;   // Snake
        default: return position;
    }
}

int rollDice() {
    return (rand() % 6) + 1;
}

void playTurn(string playerName, int &position) {
    cout << playerName << "'s turn. Press Enter to roll the dice...";
    cin.ignore();
    
    int dice = rollDice();
    cout << playerName << " rolled a " << dice << "." << endl;

    if (position + dice <= WINNING_POSITION) {
        position += dice;
        cout << playerName << " moves to " << position << "." << endl;
        position = checkSnakesAndLadders(position);

        if (position != WINNING_POSITION) {
            cout << playerName << " is now at " << position << "." << endl;
        }
    } else {
        cout << "Roll too high. Stay at " << position << "." << endl;
    }
}

int main() {
    srand(time(0));
    string player1 = "Player 1";
    string player2 = "Player 2";
    int pos1 = 0, pos2 = 0;

    cout << "====== Snake and Ladder Game ======" << endl;
    cout << "First to reach 100 wins!" << endl << endl;

    while (true) {
        playTurn(player1, pos1);
        if (pos1 == WINNING_POSITION) {
            cout << player1 << " wins the game! ??" << endl;
            break;
        }

        playTurn(player2, pos2);
        if (pos2 == WINNING_POSITION) {
            cout << player2 << " wins the game! ??" << endl;
            break;
        }
    }

    return 0;
}

