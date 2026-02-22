#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto flight : flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            adj[from].push_back({to, price});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<pair<int, pair<int,int>>> q;
        q.push({0, {0, src}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int stops = front.first;
            int currCost = front.second.first;
            int node = front.second.second;

            for(auto neighbourData : adj[node]){
                int nextNode = neighbourData.first;
                int edgeCost = neighbourData.second;

                if((currCost + edgeCost < dist[nextNode]) && (stops <= k)){
                    dist[nextNode] = currCost + edgeCost;
                    q.push({stops + 1, {dist[nextNode], nextNode}});
                }
            }
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};