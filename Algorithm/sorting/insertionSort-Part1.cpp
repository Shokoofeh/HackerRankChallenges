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
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
//using namespace std;

void printX (int a)
{
    std::cout << a << " ";
}

void insertionSort(std::vector <int>  ar) {
    size_t sz = ar.size();

    if (ar.empty() || sz == 1 || ar[sz - 1] >= ar[sz - 2]) {
        return;
    }

    int tmp = ar[sz - 1];
    int i;
    for (i = sz - 2; i >= 0; i--) {
        if (ar[i] > tmp) {
            ar[i + 1] = ar[i];
            std::for_each(ar.begin(), ar.end(), printX);
            std::cout << "\n";
        }
        else
        {
            ar[i + 1] = tmp;
            std::for_each(ar.begin(), ar.end(), printX);
            std::cout << "\n";
            return;
        }
    }

    ar[0] = tmp;
    std::for_each(ar.begin(), ar.end(), printX);
}
int main(void) {
    std::vector <int>  _ar;
    int _ar_size;
    std::cin >> _ar_size;
    for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        int _ar_tmp;
        std::cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }

    insertionSort(_ar);
    return 0;
}

