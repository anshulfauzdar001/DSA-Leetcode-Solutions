class Solution {
public:
    void dfs(int node, int parent,
             vector<vector<int>> &adj,
             vector<int> &disc,
             vector<int> &low,
             vector<vector<int>> &result,
             int &timer) {
        
        disc[node] = low[node] = timer++;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;

            if (disc[neighbor] == -1) {
                // Not visited
                dfs(neighbor, node, adj, disc, low, result, timer);

                low[node] = min(low[node], low[neighbor]);

                // Bridge condition
                if (low[neighbor] > disc[node]) {
                    result.push_back({node, neighbor});
                }
            } else {
                // Back edge
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        
        // Build graph
        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n, -1), low(n, -1);
        vector<vector<int>> result;
        int timer = 0;

        // Handle disconnected graph
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                dfs(i, -1, adj, disc, low, result, timer);
            }
        }

        return result;
    }
};