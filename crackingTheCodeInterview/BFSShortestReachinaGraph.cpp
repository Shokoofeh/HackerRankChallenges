#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Graph {
public:
    vector<int> distance;
    vector<bool> visited;
    vector<vector<int>> adj;
    queue<int> q;
    Graph(int n) {
        vector<int> dummy;
        for (int i = 0; i < n; i++) {
            distance.push_back(-1);
            visited.push_back(false);
            adj.push_back(dummy);
        }
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> shortest_reach(int start) {
        distance[start] = 0;
        q.push(start);
        int dist = 6;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (int i = 0; i < adj[n].size(); i++) {
                int m = adj[n][i];
                if (visited[m] != true) {
                    distance[m] = dist + distance[n];
                    visited[m] = true;
                    q.push(m);
                }
            }
        }
        return distance;
    }
};

int main() {
    int queries;
    cin >> queries;
    for (int t = 0; t < queries; t++) {
        int n, m;
        cin >> n;
        Graph graph(n);
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        vector<int> distances = graph.shortest_reach(startId);
        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

