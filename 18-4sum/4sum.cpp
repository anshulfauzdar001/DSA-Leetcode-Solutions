class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            long long minSum = (long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
            if (minSum > target) break;
            long long maxSum = (long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
            if (maxSum < target) continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long min2 = (long long)nums[i] + nums[j] + nums[j+1] + nums[j+2];
                if (min2 > target) break;
                long long max2 = (long long)nums[i] + nums[j] + nums[n-1] + nums[n-2];
                if (max2 < target) continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l-1]) l++;
                        while (l < r && nums[r] == nums[r+1]) r--;
                    }
                    else if (sum < target) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};