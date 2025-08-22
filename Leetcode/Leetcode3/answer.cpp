#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // We can use the sliding window method of variable length

        size_t L = 0;
        // Because we cannot have repeated characters, we can use a set
        
        std::unordered_set<char> letters = {};
        int longest_sub = 0;

        for(size_t R  = 0; R < s.length(); R++){

            while(letters.find(s[R]) != letters.end()){
                letters.erase(s[L]);
                L++;
            }

            int current_length = R - L + 1;
            longest_sub = max(current_length, longest_sub);

            // We add the righmost element
            letters.insert(s[R]);
        }

        return longest_sub;
    
    }
};
