#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector <int> rank, parent;
public : 
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
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int wires = connections.size();
        if (n-1>wires) return -1;
        DisjointSet ds(n);
        for (auto it : connections) {
            ds.unionByRank(it[0], it[1]);
        }
        unordered_set <int> checker;
        for (int i=0; i<n; i++) {
            checker.insert(ds.findUpParent(i));
        }
        return checker.size()-1;
    }
};