# Description

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

**Example 1:**

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

**Constraints:**

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

**Follow up: Could you find an algorithm that runs in O(m + n) time?**


# Explanation of the implementation

As base case or direct case, we need to consider the situations in which one of the input strings is empty.In those scenarios, we must return an empty string.

- **If len(s) == 0.** Then there is no window to construct so "" is the only possibility.

- **If len(t) == 0.** Then there is no window to create in s and we are not searching for any substring.

- Two maps are required to store the necessary information to analize the input string s.

	1. **One map for t** that contains for each letter in t the number of times it appears

	2. **Another map for s** that stores for each of the letters of t, the amount of occurences of each of them in the string s.

- Moreover, **two integer variables are needed**: needed and having.

	1. **needed**: stores the number of letters of t, basically the total number of matches we need with the string s to find a valid window.

	2. **having**: stores the number of letters from s that match with the letters from t.

**With this in mind, we know that** a window will be valid when having == needed.

Therefore, the algorithm works as follows.

1. We first check the direct/base situations explained above.

2. We then stores in the map for t(letters_t) the number of occurences of each of its letters and initialize needed with the length of t because it is the number of letters we need in s to obtain a valid window.

3. We initialize three variables that will store the minimum length of all the valid windows that have been found and two indices to know where that minimum length window is located.

4. The sliding window approach is followed:
	- We iterate through the whole string using R.

	- If having < needed this means that we are not in a valid window.
	As a result, we move the right index R to expand the window and look for a valid one. Each time we expand R, we analyze if the added letter was a letter in t by using its map. If it was, we increase the counter of that letter in the map for s.

	- if letters_s[s[R]] <= letters_t[s[R]] -> this means that the added letter was one that we were looking for. Therefore, we increase having.

5. Within the for loop, we perform a while loop that considers the case in which we have having >= needed. Meaning that we are in a valid window.

	- We check if the length of the current valid window is smaller than the one that was previously stored. If it is the case, we update the indices and the minimum length variables.

	- Once we are in a valid window, to look for the smallest one, we move the left index until the window becomes non valid, updating the minimum length if necessary.

6. This way when the window becomes invalid, another for loop iteration will be executed, moving R allowing us to search another possible valid window.

**This algorithm is repeated until R reaches the last element of the array**. When we reach this situation, the only possibility for us to find a smallest window is by moving L.

7. When the loop terminates, we check if the length was updated. If it was not it means that we did not find any window in the input string s so we must return the empty one.

8. Finally by using the indexes, we take the substring from s and return it.

# Time complexity

We are iterating through the string t to keep track of its letters. This leads to an initial O(t) being t the size of the string t.

Then, we iterate once through each of the letters of s by using the for and while loops. As a result, the loops contribute O(n), being n the size of the string s.

**Summing both fragments of the algorithm, we obtain**:

T(n,t) = O(t) + O(n) = O(t + n)
**Linear with respect of both string**

# Space complexity

Simple variables constribute O(1) to the space complexity. In our case, the only data structures being used apart from simple variables are the two maps: letters_s and letters_t.

Both letters_s and letters_t will have as many entries as different letters there are in t. The worst case is that one in which all the letters of t are different, hence matching the length of t.

If we consider t as the length of the string t, the space complexity will be:

S(t) = O(t) **letters_t** + O(t) **letters_s** = O(2t) = O(t)

**Hence the space complexity is linear** with respect of the size of t.



