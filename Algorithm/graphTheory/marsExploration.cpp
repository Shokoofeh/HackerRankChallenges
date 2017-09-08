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


int main() {
    string S;
    cin >> S;
    size_t count = 0;
    string str = "SOS";

    for (size_t i = 0; i < S.size(); i++)
    {
        if (S[i] != str[i % 3])
        {
            count ++;
        }
    }

    cout << count;
    return 0;
}

