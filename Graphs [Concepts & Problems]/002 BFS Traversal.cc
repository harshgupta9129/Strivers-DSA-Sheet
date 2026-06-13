#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    queue <int> q;
    q.push(0);
    vector <int> visited(n, 0);
    visited[0]=1;
    vector <int> ans;
    while (q.size()!=0) {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (int x : adj[temp]) {
            if (visited[x]==0) {
                q.push(x);
                visited[x]=1;
            }
        }
    }
    return ans;
}