#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

        // adjacency list 
        vector <vector <int>> adj(V);
        for (vector <int> p : edges) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        // Not Needed Vis Vector
        // BFS Traversal 
        vector <int> dis(V, -1);
        queue <int> q;
        q.push(src);
        dis[src]=0;
        while (q.size()) {
            int node = q.front();
            q.pop();
            for (int next : adj[node]) {
                if (dis[next]==-1) {
                    dis[next]=dis[node]+1;
                    q.push({next});
                }
            }
        }
        for (int i=0; i<V; i++) {
            if (dis[i]==INT_MAX) dis[i]=-1;
        }
        return dis;
    }
};
