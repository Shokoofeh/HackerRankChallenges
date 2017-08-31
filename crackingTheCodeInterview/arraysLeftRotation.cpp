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

void array_left_rotation_once(vector<int>& a, int n) {
    int tmp = a[0];

    for (int i = 0; i < n-1; i++)
        a[i] = a[i+1];

    a[n-1] = tmp;
}

vector<int> array_left_rotation(const vector<int>& a, int n, int k) {
    
    vector<int> res(a);

    if(a.empty() || a.size() == 1) return res;

    for(int i = 0; i < n; i++)
        res[i] = a[(k+i)%n];
    
    return res;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}

