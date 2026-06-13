#include <bits/stdc++.h>
using namespace std;

bool detect(int node, vector<int>& visited, vector<vector<int>>& adj) {
    queue<pair<int, int>> q;

    visited[node] = 1;
    q.push({node, -1});

    while (!q.empty()) {
        int src = q.front().first;
        int prt = q.front().second;
        q.pop();

        for (int x : adj[src]) {
            if (!visited[x]) {
                visited[x] = 1;
                q.push({x, src});
            }
            else if (x != prt) {
                return true;
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    vector<vector<int>> adj(n + 1);

    for (auto &p : edges) {
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }

    vector<int> visited(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (detect(i, visited, adj))
                return "Yes";
        }
    }

    return "No";
}