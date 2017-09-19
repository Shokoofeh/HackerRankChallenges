#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
// using namespace std;

bool isSorted (std::string::iterator first, std::string::iterator last)
{
    if (first == last) return true;
    std::string::iterator next = first;
    while (++next != last) {
        if (*next < *first)
            return false;
        ++first;
    }
    return true;
}

int main() {
    unsigned int T;
    bool result = true;
    std::cin >> T;

    for (unsigned int t = 0; t < T; t++) {

        result = true;
        
        unsigned int N;
        std::cin >> N;

        std::vector<std::string> grid(N);
        for (unsigned int r = 0; r < N; r++) {
            std::cin >> grid[r];
            std::sort(grid[r].begin(), grid[r].end());
        }

        for (unsigned int c = 0; c < N; c++) {
            std::string v;
            for (unsigned int r = 0; r < N; r++) {
                v.push_back(grid[r][c]);
            }
            if (!isSorted(v.begin(), v.end())) {
                result = false;
                break;
            }
        }
        if (result) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    } // T for loop
    return 0;
}


