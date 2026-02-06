/*
LeetCode Problem: 560. Subarray Sum Equals K
Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/

Approach:
- Use Prefix Sum + Hash Map.
- Maintain a running prefix sum.
- If (current_sum - k) has appeared before,
  it means there exists a subarray ending here with sum = k.

Key Idea:
prefixSum[j] - prefixSum[i] = k
=> prefixSum[i] = prefixSum[j] - k

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1; // Base case

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            if (freq.find(prefixSum - k) != freq.end()) {
                count += freq[prefixSum - k];
            }

            freq[prefixSum]++;
        }

        return count;
    }
};
