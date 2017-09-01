#include<iostream>
#include<vector>
using namespace std;

class Cell {
public:
    int row;
    int col;
    Cell (int r, int c) : row (r), col (c) {}
    Cell () {}
    int distance ( Cell ce ) {
        return abs(ce.col - col) + abs(ce.row - row);
    }
    int distance( int r, int c) {
        return abs(c - col) + abs(r - row);
    }

};

bool valid (Cell c) {
    return (c.row > 0 && c.col > 0 && c.row < 5 && c.col < 5);
}

Cell findClosestDirt (int posr, int posc, const vector < string > & b) {
    Cell d(0, 0);
    Cell result;
    int mindis = 1000;

    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            d.row = r;
            d.col = c;
            if (b[r][c] == 'd')
            {
                if (d.distance (posr, posc) < mindis) {
                    mindis = d.distance (posr, posc);
                    result = d;
                }
            }
        }
    }

    return result;
}


inline void moveLeft () {
    cout << "LEFT\n";
}


inline void moveRight () {
    cout << "RIGHT\n";
}


inline void moveUp () {
    cout << "UP\n";
}


inline void moveDown () {
    cout << "DOWN\n";
}

inline void cleanCell () {
    cout << "CLEAN\n";
}


void next_move (int posr, int posc,  vector <string> board) {
    if (board[posr][posc] == 'd') cleanCell();

    Cell cell = findClosestDirt (posr, posc, board);
    int distr = posr - cell.row;
    int distc = posc - cell.col;

    if ( distr < 0) moveDown();
    else if ( distr > 0) moveUp();
    else if (distc < 0) moveRight();
    else if (distc > 0) moveLeft();
}
int main(void) {
    int pos[2];
    vector <string> board;
    cin >> pos[0] >> pos[1];
    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}


