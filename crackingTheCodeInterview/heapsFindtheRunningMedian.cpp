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

class Heap {
public:
    int size;
    vector<int> items;
    vector<int> sortedArray;
    bool hasParent (int i) { return (i > 0); }
    bool hasLeftChild (int i) { return validIndex(2 * i + 1); }
    bool hasRightChild (int i) { return validIndex(2 * i + 2); }
    bool validIndex (int index) { return (index >= 0 && index < size); }
    int parentIndex (int i) { return (i - 1) / 2; }
    int leftChildIndex (int i) { return 2 * i + 1; }
    int rightChildIndex (int i) { return 2 * i + 2; }
    void swap(int a, int b) {
        if (!validIndex(a) || !validIndex(b)) return;
        int tmp = items[a];
        items[a] = items[b];
        items[b] = tmp;
    }

    Heap(): size(0) {}
    int getTop() {return items[0];}
    int getSize() {return size;}
    int pop() {
        int top = items[0];
        items[0] = items[size - 1];
        items.pop_back();
        size--;
        heapifyDown();
        return top;
    }
    void printHeap() {
        cout << "Heap: ";
        for (auto a : items)
            cout << a << " ";
        cout << endl;
    }
    void printSortedArray() {
        cout << "Sorted Array: ";
        for (auto a : sortedArray) cout << a << " " ;
        cout << endl;
    }
    void insert(int val) {
        items.push_back(val);
        size++;
        heapifyUp();
    }
    virtual void heapifyDown () = 0;
    virtual void heapifyUp () = 0;

};

class MaxHeap : public Heap {
public:
    void heapifyUp() {
        int index = size - 1;
        while (hasParent(index) &&   items[parentIndex(index)] < items[index] ) {
            swap(parentIndex(index), index);
            index = parentIndex(index);
        }
    }

    void heapifyDown() {
        if (size <= 1) return;
        int in = 0;
        while (hasLeftChild(in)) {
            int biggerIndex = leftChildIndex(in);
            if (hasRightChild(in) && items[rightChildIndex(in)] > items[leftChildIndex(in)])
                biggerIndex = rightChildIndex(in);
            if (items[in] > items[biggerIndex]) break;
            swap(in, biggerIndex);
            in = biggerIndex;
        }
    }
};

class MinHeap : public Heap {
    void heapifyUp() {
        int index = size - 1;

        while (hasParent(index) &&   items[parentIndex(index)] > items[index] ) {
            swap(parentIndex(index), index);
            index = parentIndex(index);
        }
    }

    void heapifyDown() {
        if (size <= 1) return;

        int in = 0;

        while (hasLeftChild(in)) {
            int smallerIndex = leftChildIndex(in);
            if (hasRightChild(in) && items[rightChildIndex(in)] < items[leftChildIndex(in)])
                smallerIndex = rightChildIndex(in);
            if (items[in] <= items[smallerIndex]) break;
            swap(in, smallerIndex);
            in = smallerIndex;
        }
    }
};

void balanceHeaps( Heap* mn,  Heap* mx) {

    while (abs(mn->getSize() - mx->getSize()) > 1) {
        if (mn->getSize() > mx->getSize())
        {
            mx->insert(mn->getTop());
            mn->pop();
        }
        else
        {
            mn->insert(mx->getTop());
            mx->pop();
        }
    }
}

double runningMedian(Heap* mn, Heap* mx) {
    double median = 0;

    if (mn->getSize() == mx->getSize())
        median = double(mn->getTop() + mx->getTop()) / 2.0;
    else if (mn->getSize() > mx->getSize())
        median = double(mn->getTop());
    else
        median = double(mx->getTop());

    return median;
}



int main() {
    int n;
    cin >> n;
    vector<int> a;
    Heap* minHeap = new MinHeap;
    Heap* maxHeap = new MaxHeap;

    for (int a_i = 0; a_i < n; a_i++) {
        int b;
        cin >> b;
        if (maxHeap->getSize() == 0) {
            maxHeap->insert(b);
        } else {
            if (b < maxHeap->getTop()) maxHeap->insert(b);
            else minHeap->insert(b);
        }
        balanceHeaps(minHeap, maxHeap);
        cout.precision(1);
        cout << fixed <<  runningMedian(minHeap, maxHeap) << endl;
    }

    delete minHeap;
    delete maxHeap;
    return 0;
}

