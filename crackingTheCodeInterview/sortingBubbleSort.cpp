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

int bubbleSort(vector<int>& a){
    if (a.size() < 2) return 0;

    int numSwaps = 0;
    size_t n = a.size();

    for (int i = 0; i < a.size(); i++) {
        int numberOfSwaps = 0;

        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }
        numSwaps += numberOfSwaps;
        n--;
        if (n == 1) break;
    }

    return numSwaps;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
    }

    cout << "Array is sorted in " << bubbleSort(a) << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1] ;
    return 0;
}

