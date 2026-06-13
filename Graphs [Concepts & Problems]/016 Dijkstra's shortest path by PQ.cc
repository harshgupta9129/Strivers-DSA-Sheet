#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source) {
    vector <vector <pair<int,int>>> adj(vertices);
    vector <int> distance(vertices, INT_MAX);
    for (vector <int> p : edge) {
        adj[p[0]].push_back({p[1],p[2]});
        adj[p[1]].push_back({p[0],p[2]});
    }
    priority_queue <pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, source});
    distance[source]=0;
    while (q.size()) {
        int dis = q.top().first;
        int node = q.top().second;
        q.pop();
        for (auto it : adj[node]) {
            int next = it.first;
            int d = it.second;
            if (dis+d<distance[next]) {
                distance[next]=dis+d;
                q.push({dis+d, next});
            }
        }
    }
    return distance;
}