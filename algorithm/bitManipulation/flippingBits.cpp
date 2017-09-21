#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

unsigned int flipBits(unsigned int input) {
    unsigned int output = input;
    
    for(unsigned int i = 0; i < 32; i ++) {
        output = output ^ (1 << i);
    }
    return output;
}


int main() {
    unsigned int T;
    std::cin >> T;
    
    for(unsigned int i = 0; i < T; i++) {
        unsigned int input;
        std::cin >> input;
        std::cout << flipBits(input) << std::endl;
    }
    return 0;
}

