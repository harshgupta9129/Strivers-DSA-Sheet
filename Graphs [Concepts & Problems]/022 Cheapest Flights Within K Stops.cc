// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
// https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // Adjacency list: {destination, cost}
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {current cost, current city, flights used so far}
        queue<tuple<int, int, int>> q;

        q.push({0, src, 0});

        // Minimum cost found so far to reach each city
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        while (!q.empty()) {

            auto [currCost, city, stops] = q.front();
            q.pop();

            // If flights used exceed the allowed limit,
            // do not explore this path further.
            if (stops > k) continue;

            // Explore all outgoing flights from current city
            for (auto [nextCity, fare] : adj[city]) {

                int newCost = currCost + fare;

                /*
                 * Core Logic:
                 * If we found a cheaper way to reach nextCity,
                 * update its cost and continue exploring from it.
                 *
                 * Since BFS processes states level-by-level
                 * (increasing number of flights/stops),
                 * we only keep the best cost discovered so far.
                 */
                if (newCost < cost[nextCity]) {

                    cost[nextCity] = newCost;

                    // Move to next city with one more flight used
                    q.push({newCost, nextCity, stops + 1});
                }
            }
        }

        // If destination was never reached, return -1
        return (cost[dst] == INT_MAX ? -1 : cost[dst]);
    }
};