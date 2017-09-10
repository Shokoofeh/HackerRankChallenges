#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd (int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  int temp = gcd(a, b);
  return temp ? (a / temp * b) : 0;
}


int gcd (const std::vector <int> & v) {
  if (v.empty()) { 
    return 0;
  }
  int g = v[0];
  for (int i = 1; i < v.size(); i++) {
    g = gcd(g, v[i]);
  }
  return g;
}

int lcm (const std::vector <int>& v) {
  if (v.empty()) return 0;
  int l = v[0];
  for (int i = 0; i < v.size(); i++) {
    l = lcm(l, v[i]);
  }
  return l;
}
bool factorsX(const std::vector <int>& a, int x) {
  for (int i = 0; i < a.size(); i++) {
    if (x % a[i] != 0) {
      return false;
    }
  }
  return true;
}

bool xFactors (const std::vector<int>& v, int x) {
  if (v.empty()) {
    return false;
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] % x != 0) {
      return false;
    }
  }
  return true;
}

int getTotalX(vector <int> a, vector <int> b) {
  int count = 0;
  int gb = gcd(b);
  int la = lcm(a);

  for (int x = la; x <= gb; x += la) {
    if (factorsX(a, x) && xFactors(b, x)) {
      count++;
    }
  }
  return count;
}

int main() {
  int n;
  int m;
  cin >> n >> m;
  vector<int> a(n);
  for (int a_i = 0; a_i < n; a_i++) {
    cin >> a[a_i];
  }
  vector<int> b(m);
  for (int b_i = 0; b_i < m; b_i++) {
    cin >> b[b_i];
  }
  int total = getTotalX(a, b);
  cout << total << endl;
  return 0;
}

