class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        helper(i + 1, nums, curr, ans);
        curr.pop_back();
        helper(i + 1, nums, curr, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0, nums, curr, ans);
        return ans;
    }
};
