#include<iostream>
using namespace std;

bool isWin(char game[3][3]){
    bool win = false;
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
    // col
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    // dia
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    return win;
}

void showMap(char game[3][3]){
    cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
    cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
    cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
}

int main(){
    int i,j;
    char game[3][3] = {' '};
    for (int gn = 0; gn < 3; gn++) {
        for (int hn = 0; hn < 3; hn++) 
            game[gn][hn] = ' ';
    }
    char player1 = 'X';
    char player2 = 'O';
    bool turn = true;
    cout << "X = Player 1" << endl << "O = Player 2" << endl;

    for (int n = 0; n < 9; n++) {
        turn = !turn;
        if (turn == false)
            cout << "Player 1: ";
        else 
            cout << "Player 2: ";
        cout << "Which cell to mark? i:[0..2] j:[0..2]: ";
        cin >> i >> j;

        if (game[i][j] == ' ') {
            if (turn == false)
                game[i][j] = player1;
            else
                game[i][j] = player2;
        }
        else {
            turn = !turn;
            n = n - 1;
        }
        
        if (isWin(game)) {
            cout << "Win!" << endl;
            showMap(game);
            break;
        }
        showMap(game);
        if (n == 8)
            cout << "Tie!" << endl;
    }
    return 0;
}
