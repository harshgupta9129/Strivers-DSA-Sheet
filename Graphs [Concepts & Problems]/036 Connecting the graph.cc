#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector <int> rank, parent;
    DisjointSet (int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i=0; i<n; i++) parent[i]=i;
    }

    int findUpParent (int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUpParent(parent[node]);
    }

    void unionByRank (int u, int v) {
        int ulp_u = findUpParent(u);
        int ulp_v = findUpParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        if (edge.size()<n-1) return -1;
        for (auto it : edge) {
            ds.unionByRank(it[0], it[1]);
        }
        int groups = 0;
        for (int i=0; i<n; i++) {
            if (ds.parent[i]==i) groups++;
        }
        return groups-1;
    }
};