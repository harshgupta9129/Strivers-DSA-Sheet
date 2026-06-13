#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

int main() {
    int n, m;
    vector <int> adj[m+1];
    for (int i=0; i<m; i++) {
        int u,v;
        cin>>u>>v;
        // Undirected 
        adj[u].push_back(v);
        adj[v].push_back(u);

        // Directed
        adj[u].push_back(v);
    }
}