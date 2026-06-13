#include<bits/stdc++.h>
using namespace std;


// Need Reverse
bool dfs (int node, vector <int> &pathvisited, vector <int> &isvisited, string &ans, vector <vector <int>> &adj) {
    isvisited[node]=1;
    pathvisited[node]=1;
    for (int x : adj[node]) {
        if (!isvisited[x]) {
            if (dfs(x, pathvisited, isvisited, ans, adj)) return true;
        }
        else if (pathvisited[x]) return true;
    }
    ans.push_back(node+'a');
    pathvisited[node]=0;
    return false;
}

// Kahn's Alogrithm
// Don't Need Reverse Already Gives Topological Sort
string bfs (vector <vector <int>> &adj, int k) {
    vector <int> indegree(k, 0);
    for (vector <int> p : adj) {
        for (int x : p) indegree[x]++;
    }
    queue <int> q;
    string ans;
    for (int i=0; i<k; i++) if (indegree[i]==0) q.push(i);
    while (q.size()) {
        int node = q.front();
        ans.push_back(node+'a');
        q.pop();
        for (int next : adj[node]) {
            indegree[next]--;
            if (indegree[next]==0) q.push(next);
        }
    }
    if (ans.length()==k) return ans;
    return "";
}

string getAlienLanguage(vector<string> &dictionary, int k)
{
    vector <vector <int>> adj(k);
    for (int i=0; i<dictionary.size()-1; i++) {
        string s1 = dictionary[i];
        string s2 = dictionary[i+1];
        int j=0;
        int l1 = s1.length();
        int l2 = s2.length();
        int l = min(l1, l2);
        while (j<l && s1[j]==s2[j]) j++;
        if (j<l) {
            adj[s1[j]-'a'].push_back(s2[j]-'a');
        }
    }
    // vector <int> isvisited(k, 0);
    // vector <int> pathvisited(k, 0);
    // string ans="";
    // for (int i=0; i<k; i++) {
    //     if (!isvisited[i]) {
    //         if (dfs(i, pathvisited, isvisited, ans, adj))
    //             return "";
    //     }
    // }
    // reverse(ans.begin(), ans.end());
    // return ans;
    return bfs(adj, k);
}