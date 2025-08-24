# Description

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

**Example 1:**

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

**Example 2:**

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

**Constraints:**

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

# Explanation

We have used the **sliding window approach with varible window length.**

We declare and initialize the minimum_length, the current sum and the left-window-index that will be neede for the problem.

Afterwards, we iterate through the whole array once, expanding the window towards the right until the sum >= target. In that moment, we have found a valid window so we analyze its length. If it was smaller than the previous valid window, then we update the minimum length accordingly.

**If we are in a valid window** meaning that cur_sum + nums[R] >= target, then we try to find one of smaller length by moving the index L to the right, updating the sum accordingly.

**Finally** if we observe that the length was not updated during the execution that means that there was not valid window, so we return 0. **If there was a valid one**, we simply return the minimum length.

# Time complexity

The sliding window approach that I have followed, goes through each element of the array just once. As a result, it is: **T(n) = O(n)**

# Space complexity

Within the algorithm, we have used simple variables apart(R,L,minimum_length and cur_sum) from the vector that was provided as an argument that does not count for the space complexity.

Therefore, **S(n) = O(1)**
