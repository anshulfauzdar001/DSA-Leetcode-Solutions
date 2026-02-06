/*
LeetCode Problem: 26. Remove Duplicates from Sorted Array
Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Approach:
- Use two pointers.
- Pointer `i` keeps track of the index of the last unique element.
- Traverse the array using pointer `j`.
- When nums[j] is different from nums[i], increment `i` and update nums[i].

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // Index of last unique element

        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
