#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public:
    vector <int> rank, parent;
    DisjointSet (int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i=0; i<n+1; i++) parent[i]=i;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for (auto it : edges) {
            if (ds.findUpParent(it[0])==ds.findUpParent(it[1])) return it;
            ds.unionByRank(it[0], it[1]);
        }
        return {};
    }
};