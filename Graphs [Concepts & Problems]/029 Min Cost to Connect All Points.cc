#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector <vector <pair<int, int>>> adj(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i==j) continue;
                adj[i].push_back({j, abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        }
        priority_queue <pair<int, int>, vector <pair<int,int>>, greater<pair<int,int>>> pq;
        vector <bool> vis(n, 0);
        pq.push({0, 0});
        int minCost = 0;
        while (!pq.empty()) {
            auto [wt, point] = pq.top();
            pq.pop();
            if (vis[point]) continue;
            minCost+=wt;
            vis[point]=1;
            for (auto [nextPoint, w] : adj[point]) {
                if (vis[nextPoint]) continue;
                pq.push({w, nextPoint});
            }
        }
        return minCost;
    }
};