#include <bits/stdc++.h>
using namespace std;


class IceCream {

public:
  int flavor;
  int index;

  IceCream(int flavor, int index) {
    this->flavor = flavor;
    this->index = index;
  }
};

bool compare(IceCream i, IceCream j) { return (i.flavor < j.flavor); }


int binarySearch(int first, int last, vector<IceCream> arr, int search) {
  int mid;
  if (last < first) return -1;
  while (first <= last) {
    mid = first + (last - first) / 2;
    //cout << "first: " << first << " last: " << last << " mid: " << mid << endl;

    if (arr[mid].flavor == search)
      return arr[mid].index;
    else if (search  < arr[mid].flavor ) {
      last = mid - 1;
    } else {
      first = mid + 1;
    }
  }
  if (arr[mid].flavor == search)
    return arr[mid].index;
  else
    return -1;
}

int main() {
  int t;
  int n, m;
  cin >> t;
  for (int test = 0; test < t; test++) {
    cin >> m >> n;
    vector<IceCream> arr;
    arr.reserve(n);

    for (int i = 0; i < n; i++) {
      int cost;
      cin >> cost;
      arr.push_back(IceCream(cost, i + 1));
    }

    sort(arr.begin(), arr.end(), compare);
    int firstIndex = 100000, secondIndex = 100000;
    for (int i = 0; i < n - 1 ; i++) {
      int search = m - arr[i].flavor;
      if (search >= arr[i].flavor) {
        int index = binarySearch( i + 1, n - 1, arr, search);
        if ( index != -1 ) {
          cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
          break;

        }
      }
    }

  }

}


