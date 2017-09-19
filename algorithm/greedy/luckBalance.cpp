#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    unsigned int N, K;
    std::cin >> N >> K;
    
    int l, t;
    std::vector<int> L;
    int luck = 0;
    
    for(unsigned int i = 0; i < N; i++) {
        std::cin >> l >> t;
        if(!t) {
            luck += l;
            continue;
        }
        L.push_back(l);
    }
    std::sort(L.begin(), L.end(), std::greater<int>());
    for(unsigned int i = 0; i < L.size(); i++) {
        if(i < K) {
            luck += L[i];
        }
        else {
            luck -= L[i];
        }
    }
    
    std::cout << luck << std::endl;
    return 0;
}

