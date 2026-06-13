#include <bits/stdc++.h>
using namespace std;

bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n = edges.size();
	vector <vector <int>> adj(n);
	queue <int> q;
	vector <int> color(n, -1);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) if (edges[i][j]) adj[i].push_back(j);
	}
	q.push(0);
	color[0]=0;
	while (q.size()) {
		int temp = q.front();
		q.pop();
		if (color[temp]!=-1) {
			for (int x : adj[temp]) {
				if (color[x]==-1) {
					color[x] = (color[temp]==0 ? 1 : 0);
					q.push(x);
				}
				else {
					if (color[x]==color[temp]) return false;
				}
			}
		} 
	}
	return true;
}