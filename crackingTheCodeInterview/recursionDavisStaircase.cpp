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

int NumberOfClimbWays (int n, vector<int>& v) {
    if (n < 0) return 0;
    if (n == 0) {v[0] = 0; return 0;}
    else if (n == 1) {v[n] = 1; return 1;}
    else if (n == 2) {v[n] = 2; return 2;}
    else if (n == 3) {v[n] = 4; return 4;}

    else {
        int res3 = (v[n - 3] == 0) ? NumberOfClimbWays(n - 3, v) : v[n - 3];
        int res2 = (v[n - 2] == 0) ? NumberOfClimbWays(n - 2, v) : v[n - 2];
        int res1 = (v[n - 1] == 0) ? NumberOfClimbWays(n - 1, v) : v[n - 1];
        int res = res1 + res2 + res3;
        v[n] = res;
        return res;
    }
    return -1;
}
int main() {
    int s;
    cin >> s;
    for (int a0 = 0; a0 < s; a0++) {
        int n;
        cin >> n;
        vector<int> vec(n + 1, 0);
        cout << NumberOfClimbWays(n, vec) << endl;
    }
    return 0;
}

