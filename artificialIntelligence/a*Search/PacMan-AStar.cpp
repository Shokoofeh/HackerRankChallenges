#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


class Cell {
public:
    Cell (int r, int c, char v) : row (r), col (c), value(v), visited (false), cost(0) {
    }
    Cell (): visited (false), cost(0) {
    }
    ~Cell () {}

    void print() {
        cout << row << " " << col <<  endl;
        // cout << row << " " << col << " " << value << " " << visited <<  endl;
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

    friend bool operator < (const Cell& lhs, const Cell& rhs) ;
    friend bool operator > (const Cell& lhs, const Cell& rhs) ;

    bool visited;
    char value;
    int row;
    int col;
    int cost;
};

bool operator < (const Cell& lhs, const Cell& rhs) {
    return (lhs.cost < rhs.cost);
}

bool operator > (const Cell& lhs, const Cell& rhs) {
    return (lhs.cost > rhs.cost);
}

class Grid {
public:
    Grid (int r, int c, int rr, int rc, int tr, int tc) :
        row_ (r),
        col_ (c),
        step_cost_(1)
    {}
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
    void aStarSearch ();
    void printPath ();
    void setPacmanCell(int r, int c);
    void setFoodCell(int r, int c);
    void setHeuristic();

    vector < vector < Cell* > > grid;
    vector < vector < int > > heuristics;
    stack < Cell* > path;
    vector < Cell* > explored_path;
    map<Cell*, Cell*> parent_map;
    Cell* pacman;
    Cell* food;

private:
    int row_;
    int col_;
    int step_cost_;

};


void Grid::aStarSearch () {

    Cell* curr_cell = pacman;
    Cell* adj_cell;
    priority_queue <Cell**, vector <Cell*>, less<vector <Cell*>::value_type> > pq;

    pq.push(curr_cell);
    explored_path.clear();

    while (!pq.empty()) {

        curr_cell = pq.top();
        curr_cell->visited = true;
        if (explored_path.empty() ||
                find (explored_path.begin(), explored_path.end(), curr_cell) == explored_path.end()) {
            explored_path.push_back(curr_cell);
        }

        pq.pop();

        if (curr_cell->row == food->row &&
                curr_cell->col == food->col &&
                curr_cell->value == food->value) {
            return;
        }

        if (isUpValid(curr_cell)) {
            adj_cell = getUpCell(curr_cell);
            if (!adj_cell->visited && adj_cell->value != '%') {
                adj_cell->cost = heuristics[adj_cell->row][adj_cell->col] + step_cost_;
                adj_cell->visited = true;
                pq.push(adj_cell);
                parent_map[adj_cell] = curr_cell;
            }
        }

        if (isLeftValid(curr_cell)) {
            adj_cell = getLeftCell(curr_cell);
            if (!adj_cell->visited && adj_cell->value != '%') {
                adj_cell->cost = heuristics[adj_cell->row][adj_cell->col] + step_cost_;
                adj_cell->visited = true;
                pq.push(adj_cell);
                parent_map[adj_cell] = curr_cell;
            }
        }

        if (isRightValid(curr_cell)) {
            adj_cell = getRightCell(curr_cell);
            if (!adj_cell->visited && adj_cell->value != '%') {
                adj_cell->cost = heuristics[adj_cell->row][adj_cell->col] + step_cost_;
                adj_cell->visited = true;
                pq.push(adj_cell);
                parent_map[adj_cell] = curr_cell;
            }
        }

        if (isDownValid(curr_cell)) {
            adj_cell = getDownCell(curr_cell);
            if (!adj_cell->visited && adj_cell->value != '%') {
                adj_cell->cost = heuristics[adj_cell->row][adj_cell->col] + step_cost_;
                adj_cell->visited = true;
                pq.push(adj_cell);
                parent_map[adj_cell] = curr_cell;
            }
        }
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

void Grid::setHeuristic () {
    for (int i = 0; i < row_; i++) {
        vector < int >  tmp;
        for (int j = 0; j < col_; j++) {
            tmp.push_back(abs(food->row - i) + abs (food->col - j));
        }
        heuristics.push_back(tmp);
    }
}

void Grid::setFoodCell(int r, int c) {
    food = grid[r][c];
}

void Grid::setPacmanCell(int r, int c) {
    pacman = grid[r][c];
    pacman->cost = 0;
}

void nextMove( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> string_grid) {
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

    grid->setPacmanCell(pacman_r, pacman_c);
    grid->setFoodCell(food_r, food_c);
    grid->setHeuristic();
    grid->aStarSearch();
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

    nextMove( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}

