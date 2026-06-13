#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<vector<pair<int,int>>> adj(n);
        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        set<pair<long long,int>> st;
        vector<long long> minTime(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        minTime[0] = 0;
        ways[0] = 1;
        st.insert({0, 0});
        while (!st.empty()) {
            auto [time, city] = *st.begin();
            st.erase(st.begin());
            for (auto [nextCity, t] : adj[city]) {
                if (time + t < minTime[nextCity]) {
                    if (minTime[nextCity] != LLONG_MAX) st.erase({minTime[nextCity], nextCity});
                    minTime[nextCity] = time + t;

                    // New shortest path found
                    ways[nextCity] = ways[city];
                    st.insert({minTime[nextCity], nextCity});
                }
                else if (time + t == minTime[nextCity]) {

                    // Another shortest path found
                    ways[nextCity] = (ways[nextCity] + ways[city]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};