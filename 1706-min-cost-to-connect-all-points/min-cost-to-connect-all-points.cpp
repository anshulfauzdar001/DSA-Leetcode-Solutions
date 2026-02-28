class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<int> visited(n, 0);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        
        pq.push({0, 0}); // {weight, node}
        int ans = 0;
        
        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            
            int weight = x.first;
            int node = x.second;
            
            if(visited[node]) continue;
            
            visited[node] = 1;
            ans += weight;
            
            for(int i = 0; i < n; i++) {
                if(!visited[i]) {
                    int dist = abs(points[node][0] - points[i][0]) +
                               abs(points[node][1] - points[i][1]);
                    
                    pq.push({dist, i});
                }
            }
        }
        
        return ans;
    }
};