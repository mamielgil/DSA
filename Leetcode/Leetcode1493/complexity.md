# Description

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

**Example 1:**

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

**Example 2:**

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
**Example 3:**

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

**Constraints:**

1 <= nums.length <= 105
nums[i] is either 0 or 1.

# Explanation

We have used the sliding window algorithm to look for the longest subarray that contains at most one zero.

The variables required were:
 1. **longest_string:** stores the length of the longest subarray found.

 2. **zero_in_window**: stores the number of zeros of the current window.

 3. **one_in_window**: stores whether the current window has a 1 or not and, therefore, if it can be considered as a valid window or not.

We keep expanding to the right until our window has more than one zero. In that moment, the window is not valid so we must move the index of the left until we eleminate a 0 to compensate it.


# Time complexity

We iterate through each element of the array just once with **the outer loop**. This contributes O(n) to the time complexity.

**The inner while** will be done at most n times throughout the whole execution of the algorithm. This is because everytime we move L to the right, it is never going to be able to go back again.

**Not to confuse it with O(n²)** this would be if for each iteration of the outer loop we iterate through the whole array in the inner while. This DOES NOT happen. The inner while iterates through the full array(worst case) after the outer loop has completely terminated

**Therefore**: T(n) = O(n) **outer for** + O(n) **inner while** = **O(n)**

# Space complexity

As we have used simple variables to store the necessary data for the algorithm, the space complexity is:
 **S(n) = O(1)**
