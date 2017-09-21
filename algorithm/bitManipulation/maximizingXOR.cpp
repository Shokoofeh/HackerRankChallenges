#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

int maxXor(int l, int r) {
    int xored = l ^ r;

    // find the mso most significant one -bit of xored
    unsigned short int mso = 15;
    while ((xored & (1 << mso)) == 0) {
        mso--;
    }
    // change all bits following mso to one
    unsigned short int i = 0;
    unsigned int result = 0;
    while (i <= mso) {
        result |= (1 << i++);
    }

    return result;
}

int main() {
    int res;
    int _l;
    std::cin >> _l;

    int _r;
    std::cin >> _r;

    res = maxXor(_l, _r);
    std::cout << res;

    return 0;
}

