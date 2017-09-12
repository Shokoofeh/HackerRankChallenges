#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <map>
using namespace std;


class Cell {
public:
    Cell (int r, int c, char v) : row (r), col (c), value(v), visited (false) {
    }
    Cell (): visited (false) {
    }
    ~Cell () {}

    void print() {
        cout << row << " " << col <<  endl;
    }

// TODO: FIX THIS
    inline bool operator== (const Cell* c) const {

        return (c->row == row &&
                c->col == col &&
                c->value == value);
    }

    Cell* operator= (Cell* const rhs) {
        visited = rhs->visited;
        row = rhs->row;
        col = rhs->col;
        value = rhs->value;
        return this;
    }

    bool visited;
    int row;
    int col;
    char value;
};

class Grid {
public:
    Grid (int r, int c, int rr, int rc, int tr, int tc) {
        row_ = r;
        col_ = c;

        pacman = new Cell (rr, rc, 'P');
        food = new Cell (tr, tc, '.');
    }
    ~Grid() {}

    inline Cell* getUpCell(const Cell* c) const {
        return grid[c->row - 1][c->col];
    }
    inline Cell* getLeftCell(const Cell* c) const {
        return grid[c->row][c->col - 1];
    }
    inline Cell* getRightCell(const Cell* c) const {
        return grid[c->row][c->col + 1];
    }
    inline Cell* getDownCell(const Cell* c) const {
        return grid[c->row + 1][c->col];
    }
    bool isUpValid (const Cell* c) const {
        return (c->row - 1 >= 0 && c->col >= 0
                && c->row - 1 < row_ && c->col < col_);
    }
    bool isLeftValid (const Cell* c) const {
        return (c->row >= 0 && c->col - 1 >= 0
                && c->row < row_ && c->col - 1 < col_);
    }
    bool isRightValid (const Cell* c) const {
        return (c->row >= 0 && c->col + 1 >= 0
                && c->row < row_ && c->col + 1 < col_);
    }
    bool isDownValid (const Cell* c) const {
        return (c->row + 1 >= 0 && c->col >= 0
                && c->row + 1 < row_ && c->col < col_);
    }

    void calculatePath();
    void dfs ();
    void printExploredPath ();
    void printPath ();
    vector < vector < Cell* > > grid;
    stack < Cell* > path;
    vector < Cell* > explored_path;
    map<Cell*, Cell*> parent_map;

private:
    int row_;
    int col_;
    Cell* pacman;
    Cell* food;
};


void Grid::dfs () {

    Cell* curr_cell = pacman;
    Cell* adj_cell;
    stack<Cell*> stk;

    stk.push(curr_cell);

    while (!stk.empty()) {

        curr_cell = stk.top();
        explored_path.push_back(curr_cell);
        stk.pop();
        curr_cell->visited = true;

        if (curr_cell->row == food->row &&
                curr_cell->col == food->col &&
                curr_cell->value == food->value) {
            // cout << "just checking: ";
            // parent_map[food]->print();
            return;
        }

        if (isUpValid(curr_cell)) {
            adj_cell = getUpCell(curr_cell);
            if (!adj_cell->visited && adj_cell->value != '%') {
                adj_cell->visited = true;
                stk.push(adj_cell);
                if (parent_map.find(adj_cell) == parent_map.end())
                    parent_map[adj_cell] = curr_cell;
            }
        }

        if (isLeftValid(curr_cell)) {
            adj_cell = getLeftCell(curr_cell);
            if (!adj_cell->visited && adj_cell->value != '%') {
                adj_cell->visited = true;
                stk.push(adj_cell);
                if (parent_map.find(adj_cell) == parent_map.end())
                    parent_map[adj_cell] = curr_cell;
            }
        }

        if (isRightValid(curr_cell)) {
            adj_cell = getRightCell(curr_cell);
            if (!adj_cell->visited && adj_cell->value != '%') {
                adj_cell->visited = true;
                stk.push(adj_cell);
                if (parent_map.find(adj_cell) == parent_map.end())
                    parent_map[adj_cell] = curr_cell;
            }
        }

        if (isDownValid(curr_cell)) {
            adj_cell = getDownCell(curr_cell);
            if (!adj_cell->visited && adj_cell->value != '%') {
                adj_cell->visited = true;
                stk.push(adj_cell);
                if (parent_map.find(adj_cell) == parent_map.end())
                    parent_map[adj_cell] = curr_cell;
            }
        }
    }
}

void Grid::printExploredPath () {
    for (int i = 0; i < explored_path.size(); i++) {
        explored_path[i]->print();
    }
}

void Grid::printPath () {
    while (!path.empty()) {
        Cell* cell = path.top();
        path.pop();
        cell->print();
    }
}

void Grid::calculatePath () {

    Cell* cell = explored_path.back();

    while (!(cell->row == pacman->row &&
             cell->col == pacman->col &&
             cell->value == pacman->value)) {
        path.push(cell);
        cell = parent_map[cell];
    }
    path.push(pacman);
}

void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> string_grid) {
    if (r == 0 || c == 0) {
        return;
    }

    if (string_grid.empty()) {
        return;
    }

    Grid* grid = new Grid(r, c, pacman_r, pacman_c, food_r, food_c);

    for (int i = 0; i < r; i++) {
        vector<Cell*> tmp_v;
        for (int j = 0; j < c; j++) {
            Cell* cell = new Cell(i, j, string_grid[i][j]);
            tmp_v.push_back(cell);
        }
        grid->grid.push_back(tmp_v);
    }

    grid->dfs();
    cout << grid->explored_path.size() << endl;
    grid->printExploredPath();
    grid->calculatePath();
    cout << grid->path.size() - 1 << endl;
    grid->printPath();

}
int main(void) {

    int r, c, pacman_r, pacman_c, food_r, food_c;

    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;

    vector <string> grid;

    for (int i = 0; i < r; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}



