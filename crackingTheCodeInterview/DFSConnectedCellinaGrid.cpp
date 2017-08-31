#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Point {
public:
    int row;
    int col;
    Point(int i, int j) {
        row = i;
        col = j;
    }
    Point() {}
};

bool validIndex(int x, int y, int rows, int cols) {
    return (x < rows && y < cols && x >= 0 && y >= 0);
}

Point nextUnvisited(vector<vector<bool>> v) {
    Point p(0, 0);
    for (int i = 0; i < v.size(); i ++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == false) {
                p.row = i;
                p.col = j;
                return p;
            }
        }
    }
    return p;
}

int get_biggest_region(vector< vector<int> > grid) {

    if (grid.empty()) return 0;
    vector<vector<bool>> visited;
    int nrows = grid.size();
    int ncols = grid[0].size();
    int maxreg = 0;
    int numreg = 0;
    int regsize = 0;
    int numvisited = 0;

    vector<bool>  vis(ncols, false);
    for (int i = 0; i < nrows; i++)
        visited.push_back(vis);
    Point start(0, 0);
    stack<Point> stk;
    stk.push(start);
    while (numvisited < nrows * ncols) {
        Point p;
        if (!stk.empty()) {
            p = stk.top();
            stk.pop();
        }
        else {
            p = nextUnvisited(visited);
            if (p.row == 0 && p.col == 0) break;
        }
        if (visited[p.row][p.col] == true) continue;
        if (grid[p.row][p.col] == 1) {
            visited[p.row][p.col] = true;
            if (++numvisited == nrows * ncols) break;
            regsize++;
            for (int i = -1; i <= 1; i ++) {
                for (int j = -1; j <= 1; j++) {
                    if (validIndex(p.row + i, p.col + j, nrows, ncols) && grid[p.row + i][p.col + j] == 1 && visited[p.row + i][p.col + j] == false) {
                        Point np(p.row + i, p.col + j);
                        stk.push(np);
                    }
                }
            }
            maxreg = (regsize > maxreg) ? regsize : maxreg;
            if (stk.empty()) regsize = 0;
        }
        else {
            visited[p.row][p.col] = true;
            maxreg = (regsize > maxreg) ? regsize : maxreg;
            regsize = 0;
        }
    }
    return maxreg;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n, vector<int>(m));
    for (int grid_i = 0; grid_i < n; grid_i++) {
        for (int grid_j = 0; grid_j < m; grid_j++) {
            cin >> grid[grid_i][grid_j];
        }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}

