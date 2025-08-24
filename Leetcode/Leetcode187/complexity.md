# Description

The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

**Example 1:**

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

**Example 2:**

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

**Constraints:**

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.

# Explanation

I have followed the fixed size sliding window algorithm using a map to store the number of occurences of each substring. At the end of the algorithm, I have traversed through each of the keys of the map and saved them in the map if their counter was greater than one.

# Time complexity

We use two for loops: the first one iterating through the first 10 elements and the other to iterate through the remaining ones of the provided string. Moreover, we then iterate through the whole map to store in a vector the repeating substrings.

The worst case for this map is to store all the substrings which are 
n - 9. Therefore, by combining their iterations, we obtain the following time complexity.

T(n) = O(10) + O(n - 10) + O(n - 9) = **O(2n - 9) = O(n)** 

# Space complexity

Apart from using simple data types, I have used a map and a vector.

1. In the worst case scenario, the map stores as many substrings as possible within the string.**(n is size of input string)**

	These are:
	substring 1 goes from [0,9]
	substring 2 goes from [1,10]
	substring i goes from [i, i + 9]
	**to compute i we consider as if we were dealing with the last substring:**

	i + 9 = n - 1

	i = n - 10

	Therefore, as we observe the last 9 caracters cannot be analyzed for a substring. So we will have N - 9 substrings.

	Another way of thinking about this is noticing that we can use the left index of each substring as a counter as it gets displaced by one:

	substring 1 goes from [0,9] **Left index = 0 -> substring 1** 
	substring 2 goes from [1,10] **Left index = 1 substring 2**
	substring i goes from [i, i + 9]**Left index = i substring i + 1**

	As a result, the last substring

	[n -10, n - 1] -> **Left index = n - 10 substring n- 9**

	Therefore, the map will have n - 9 keys and each of them will be of size 10 due to it being the size of the substring we are being asked for.

	Hence, **unordered_map = O((n - 9) * 10)**

	Generalizing the formula:
	**unordered:map = O((n - L - 1) * L) = O(n)
	where L is the size of the substrings asked**

2. The vector can contain at most all the substrings of the input, though it is impossible as it would entail that they are not repeated in the input. Despite this, this would be hypothetically the worst case scenario, leading to the same expression as the map.

**In conclusion,**
S(n) = O(n) + O(n) = O(n)

