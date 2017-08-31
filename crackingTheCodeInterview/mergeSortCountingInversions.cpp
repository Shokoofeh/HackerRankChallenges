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

void print_vector(vector<int> a) {
    for (auto it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
}

void merge_vectors(vector<int>& vm, vector<int>& v1, vector<int>& v2, long long& res) {

    vm.clear();
    vector<int>::iterator it_v1 = v1.begin();
    vector<int>::iterator it_v2 = v2.begin();
    if (v1.empty()) {
        vm = v2;
        return;
    }
    if (v2.empty()) {
        vm = v1;
        return;
    }

    while (it_v1 != v1.end() && it_v2 != v2.end()) {
        if (*it_v1 > *it_v2) {
            vm.push_back(*it_v2);
            res += (v1.end() - it_v1);
            it_v2++;
        } else {
            vm.push_back(*it_v1);
            it_v1++;
        }
    }

    while (it_v1 == v1.end() && it_v2 != v2.end()) {
        vm.push_back(*it_v2);
        it_v2++;
    }

    while (it_v1 != v1.end() && it_v2 == v2.end()) {
        vm.push_back(*it_v1);
        it_v1++;
        //res++;
    }


}

void count_inversions_iterative(vector<int>& a, long long& res) {
    if (a.size() == 0 || a.size() == 1) {
        res += 0;
        return;
    }

    if (a.size() == 2) {
        if (a[0] > a[1]) {
            int temp = a[0];
            a[0] = a[1];
            a[1] = temp;
            res++;
        }
        return;
    }

    int diff = a.size() % 2;
    // example size = 4 diff = 0: a1(0,1) a2(2,3)
    // example size = 3 diff = 1: a1(0,0) a2(1,2)

    auto start = a.begin();
    auto end = a.begin() + (a.size()) / 2;
    vector<int> a1(start, end);
    count_inversions_iterative(a1, res);

    start = end;
    end = a.end();
    vector<int> a2(start, end);
    count_inversions_iterative(a2, res);

    merge_vectors(a, a1, a2, res);
}

long long count_inversions(vector<int>& a) {

    long long res = 0;
    if (a.size() == 0 || a.size() == 1) return 0;
    count_inversions_iterative(a, res);
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int arr_i = 0; arr_i < n; arr_i++) {
            cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}

