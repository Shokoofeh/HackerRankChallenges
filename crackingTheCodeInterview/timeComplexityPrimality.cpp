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

typedef int long long ill;

class Prime {
public:
    map<ill, bool> primes;
    int getMax() {
        map<ill, bool>::reverse_iterator it = primes.rbegin();
        return it->first;
    }
    Prime() {
        primes[2] = true;
        primes[3] = true;
    }
    string isPrime(int n) {
        string yes = "Prime";
        string no = "Not prime";

        if (n == 1) return no;
        if (n == 2 || n == 3) return yes;
        if (primes.find(n) != primes.end()) return yes;
        int maxP = getMax();
        for (auto it = primes.begin(); it != primes.end(); it++) {
            if (n % it->first == 0)
                return no;
        }
        if (n > maxP) {
            for (ill i = maxP + 1; i < n; i++) {
                if (isPrime(i) == "Prime") primes[i] = true;
                if (n % i == 0) return no;
            }
        }
        primes[n] = true;
        return yes;
    }
};



int main() {
    int p;
    cin >> p;
    Prime* primes = new Prime;
    for (int a0 = 0; a0 < p; a0++) {
        int n;
        cin >> n;
        cout << wtf(n);
        cout << endl;
    }
    return 0;
}

