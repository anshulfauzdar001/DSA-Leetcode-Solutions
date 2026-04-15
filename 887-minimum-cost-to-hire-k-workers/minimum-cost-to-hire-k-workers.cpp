class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = quality.size();
        
        vector<pair<double, int>> workers;

        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> maxHeap;
        
        int totalQuality = 0;
        double ans = 1e18;

        for (auto &w : workers) {
            
            totalQuality += w.second;
            maxHeap.push(w.second);

            if (maxHeap.size() > k) {
                totalQuality -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k) {
                ans = min(ans, totalQuality * w.first);
            }
        }

        return ans;
    }
};