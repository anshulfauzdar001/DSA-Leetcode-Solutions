/*
LeetCode Problem: 189. Rotate Array
Problem Link: https://leetcode.com/problems/rotate-array/

Approach:
- Use the reverse technique.
- Steps:
  1. Reverse the entire array.
  2. Reverse the first k elements.
  3. Reverse the remaining elements.

Note:
- k can be greater than array length, so take k % n.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
