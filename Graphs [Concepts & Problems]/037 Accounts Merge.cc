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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map <string, int> emailToAccount;
        for (int i=0; i<n; i++) {
            for (int j=1; j<accounts[i].size(); j++) {
                if (emailToAccount.find(accounts[i][j]) == emailToAccount.end()) emailToAccount[accounts[i][j]] = i;
                else ds.unionByRank(emailToAccount[accounts[i][j]], i); 
            }
        }

        vector <unordered_set <string>> merging(n);
        for (int i=0; i<n; i++) {
            merging[ds.findUpParent(i)].insert(accounts[i].begin()+1, accounts[i].end());
        }

        vector <vector <string>> ans;
        for (int i=0; i<n; i++) {
            if (merging[i].empty()) continue;
            vector <string> temp(merging[i].begin(), merging[i].end());
            sort(temp.begin(), temp.end());
            temp.insert(temp.begin(), accounts[i][0]);
            ans.push_back(temp);
        }
        return ans;
    }
};


// #include <bits/stdc++.h>
// using namespace std;

// class DisjointSet {
//     public:
//     unordered_map <string, int> rank;
//     unordered_map <string, string> parent;

//     DisjointSet (vector <string> emails) {
//         for (string s : emails) {
//             rank[s] = 0;
//             parent[s] = s;
//         }
//     }

//     string findUpParent (string node) {
//         if (node == parent[node]) return node;
//         return parent[node] = findUpParent(parent[node]);
//     }

//     void unionByRank (string u, string v) {
//         string ulp_u = findUpParent(u);
//         string ulp_v = findUpParent(v);
//         if (ulp_u == ulp_v) return;
//         if (rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//         }
//         else if (rank[ulp_u] > rank[ulp_v]) {
//             parent[ulp_v] = ulp_u;
//         }
//         else {
//             parent[ulp_u] = ulp_v;
//             rank[ulp_v]++;
//         }
//     }
// };

// class Solution {
// public:
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

//         unordered_set <string> allEmails;
//         unordered_map <string, string> names;
//         for (auto it : accounts) {
//             for (int i=1; i<it.size(); i++) {
//                 allEmails.insert(it[i]);
//                 names[it[i]] = it[0];
//             }
//         }

//         vector <string> emails(allEmails.begin(), allEmails.end());

//         DisjointSet ds(emails);
//         for (auto it : accounts) {
//             if (it.size()>2) {
//                 for (int i=1; i<it.size()-1; i++) ds.unionByRank(it[i], it[i+1]);
//             }
//         }

//         unordered_map <string, vector<string>> collections;
//         for (string s : emails) {
//             collections[ds.findUpParent(s)].push_back(s);
//         }

//         vector <vector <string>> ans;
//         for (auto [key , val] : collections) {
//             sort(val.begin(), val.end());
//             val.insert(val.begin(), names[key]);
//             ans.push_back(val);
//         }
//         return ans;
//     }
// };
