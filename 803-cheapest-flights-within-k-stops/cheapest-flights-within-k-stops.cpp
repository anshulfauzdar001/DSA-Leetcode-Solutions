class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;

        for(int i = 0; i <= K; i++){
            vector<int> temp = dist;   // important
            for(auto &e : flights){
                int u = e[0], v = e[1], w = e[2];
                if(dist[u] != INF && dist[u] + w < temp[v]){
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
};