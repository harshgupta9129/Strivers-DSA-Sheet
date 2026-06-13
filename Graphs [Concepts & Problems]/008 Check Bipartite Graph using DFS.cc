#include <bits/stdc++.h>
using namespace std;

bool dfs (int node, int col, vector <int> &color, vector <vector <int>> &adj) {
	color[node] = col;
    for (int x : adj[node]) {
        if (color[x]==-1) {
			if (!dfs(x, !col, color, adj)) return false;
		}
        else if (color[x]==col) return false;
    }
	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	vector <vector <int>> adj(n);
	queue <int> q;
	vector <int> color(n, -1);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) if (edges[i][j]) adj[i].push_back(j);
	}
	for (int i=0; i<n; i++) {
		if (color[i]==-1) {
			if (!dfs(i, 0, color, adj)) return false;
		} 
	}
	return true;
}
