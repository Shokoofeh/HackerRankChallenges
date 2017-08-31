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



bool is_balanced(string s) {
    vector<char> openning;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
            openning.push_back(s[i]);
        else if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if(openning.empty()) return false;
            if(s[i] == '}') 
            {
                if(openning.back() != '{') return false;
                else openning.pop_back();
            }
            if(s[i] == ']') 
            {
                if(openning.back() != '[') return false;
                else openning.pop_back();
            }
            if(s[i] == ')') 
            {
                if(openning.back() != '(') return false;
                else openning.pop_back();
            }
        }
    }
    return (openning.empty());
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

