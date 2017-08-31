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

int number_needed(const string& a, const string& b) {
   vector<int> counts (28,0);
    int result = 0;
    
    for(int i = 0; i < a.size(); i++)
        counts[(a[i]-'a')]++;
    
    for(int i = 0; i < b.size(); i++)
        counts[(b[i]-'a')]--;
    
    for(int i = 0; i < 28; i++)
        result += abs(counts[i]);
    return result;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}

