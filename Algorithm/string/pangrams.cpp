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

int main() {
    
    std::string input_string;
    std::set<char> alphabet_set;
    char c;
    std::getline(std::cin, input_string);
    
    for (size_t i = 0; i < input_string.size(); i++) 
    {
        c = input_string[i];
        if (!isspace(c))
        {
            if (alphabet_set.find(c) == alphabet_set.end())
            {
                alphabet_set.insert(tolower(c));
            }
        }
    }
    
    if (alphabet_set.size() != 26)
    {
        std::cout << "not pangram" << std::endl;
    }
    else
    {
        std::cout << "pangram" << std::endl;
    }
    return 0;
}