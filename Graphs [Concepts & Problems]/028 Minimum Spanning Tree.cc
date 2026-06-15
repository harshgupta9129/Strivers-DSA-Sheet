// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector <vector <pair<int, int>>> adj(V);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int minSum = 0;
        priority_queue <tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        vector <tuple<int,int,int>> mst;
        pq.push({0,0,-1});
        vector <bool> vis(V, 0);
        while (!pq.empty()) {
            auto [wt, node, pt] = pq.top();
            pq.pop();
            if (vis[node]) continue;
            vis[node]=1;
            minSum+=wt;
            mst.push_back({pt, node, wt});
            for (auto [next, nwt] : adj[node]) {
                if (vis[next]) continue;
                pq.push({nwt, next, node});
            }
        }
        return minSum;
    }
};