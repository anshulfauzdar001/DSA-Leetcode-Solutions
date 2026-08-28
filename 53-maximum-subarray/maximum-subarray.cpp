class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int cur = 0 ;
        int maxSum = INT_MIN ;
        for(int i = 0 ; i<n ; i++){
            cur+=nums[i];
            maxSum = max(cur , maxSum);
            if(cur<0)cur=0;
        }
        return maxSum;
    }
};