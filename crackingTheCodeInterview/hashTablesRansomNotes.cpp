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

bool ransom_note(const vector<string>& magazine, const vector&<string> ransom) {
    size_t mlen = magazine.size();
    size_t rlen = ransom.size();
    
    map<string,int> wordmap;
    
    for(int i = 0; i < mlen; i++)
    {
        string word = magazine[i];
        map<string,int>::iterator it = wordmap.find(word);
        if(it == wordmap.end()) wordmap[word]=1;
        else it->second += 1;
    }
    
    for(int i = 0; i < rlen; i++)
    {
        string word = ransom[i];
        map<string,int>::iterator it = wordmap.find(word);
        if(it == wordmap.end()) return false;
        else if(it->second == 0) return false;
        else it->second -= 1; 
    }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

