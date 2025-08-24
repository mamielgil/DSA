# Description

Given a string s, find the length of the longest substring without duplicate characters.

 

**Example 1:**

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

**Example 2:**

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

**Example 3:**

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

**Constraints:**

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.




# Time complexity

We have a nested loop:

- The **first loop** iterates through the whole array so it is O(n).

- The **second loop** iterates through the whole array too but at most n times during the whole execution. **Do not confuse with O(n²)**. In this case, the inner while is not being executed n times per iteration but rather n times during the whole algorithm.

**As a result**,  
Outer Loop: O(n) + Inner Loop:O(n) = **O(n)**

# Space complexity

During the whole execution, we are **using variables** which entail O(1) space complexity and a set that can at most store as many different letters as there are in the alphabet that is being considered.

As a result, the set is going to store the minimum between the different letters of the alphabet and the size of the input string(considering all the letters different in string).

**As a result**,
O(min(N,Σ))

Example: Alphabet Σ  = {a,b,c,d};   Input string s = "abc";

O(min(4,3)) = O(3) <-> This is just for the sake of comprehension

