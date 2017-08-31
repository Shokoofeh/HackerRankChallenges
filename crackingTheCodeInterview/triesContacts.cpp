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

class Node {
public:
    unordered_map<char, Node*> children;
    int count;
    Node() {count = 0;}
};

class Dictionary {
private:
    Node *root;
public:
    Dictionary() {root = new Node;}
    void add(string str);
    int find(string str);
    // dstr: cleanup
};

void Dictionary::add(string str) {
    Node* node = root;
    //unordered_map<char, Node*>::iterator it = root->children.find('a');

    for (char c : str) {
        if (node->children.find(c) == node->children.end()) { // the letter is not part of the root
            Node* newNode = new Node;
            node->children.emplace(c, newNode);
            node = newNode;
        } else { // we already have the letter as one of the root's children
            node = node->children.at(c);
        }
        node->count++;
    }
}

int Dictionary::find(string str) {

    Node* node = root;

    for (char c : str) {
        if (node->children.find(c) == node->children.end()) {
            return 0;
        } else {
            node = node->children.at(c);
        }
    }
    return node->count;
}

int main() {
    int n;
    cin >> n;
    Dictionary* dictionary = new Dictionary();
    int sum = 0;
    for (int a0 = 0; a0 < n; a0++) {
        string op;
        string contact;
        cin >> op >> contact;

        if (op == "add") {
            dictionary->add(contact);
        }

        if (op == "find") {
            cout << dictionary->find(contact) << endl;
        }
    }

    // cleanup
    delete dictionary;
    return 0;
}

