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

typedef map<pair<vector<int>, int>, long long> coins_map;

coins_map my_coin_map;

int counter = 0;

long long sumCoins(const vector<int>& coins) {
    long long sum = 0;
    for (int i = 0; i < coins.size(); i++)
        sum += coins[i];
    return sum;
}

void printCoins(const vector<int>& coins) {
    cout << "printing coins: ";
    for (int i = 0; i < coins.size(); i++)
        cout << coins[i] << " ";
    cout << endl;
}

long long make_change(vector<int> coins, int money) {
    long long sum = 0;
    if (money <= 0) return 0;
    if (coins.empty()) return 0;
    if (coins.size() == 1 && coins[0] <= money && money % coins[0] == 0) return 1;

    sort(coins.begin(), coins.end());
    if (coins.front() > money) return 0;

    int biggest_coin = coins.back();

    vector<int> new_set(coins);
    new_set.pop_back();
    if (money % biggest_coin == 0) sum++;
    long long tmp;
    for (int i = 0; i * biggest_coin < money ; i++) {
        if (my_coin_map.find(pair<vector<int>, int>(new_set, money - i * biggest_coin)) != my_coin_map.end())
            tmp = my_coin_map[pair<vector<int>, int>(new_set, money - i * biggest_coin)];
        else {
            tmp = make_change(new_set, money - i * biggest_coin);
            my_coin_map[pair<vector<int>, int>(new_set, money - i * biggest_coin)] = tmp;
        }
        sum += tmp;
    }
    my_coin_map[pair<vector<int>, int>(coins, money)] = sum;
    return sum;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    my_coin_map[pair<vector<int>, int>(coins, n)] = 0;
    for (int coins_i = 0; coins_i < m; coins_i++) {
        cin >> coins[coins_i];
    }

    cout << make_change(coins, n) << endl;
    return 0;
}

