class Solution {

public:
    int longestSubarray(vector<int>& nums) {

        // Stores length of the longest string found
        int longest_string = 0;

        // Indicates if in our string there is already a 0 found
        int zero_in_window = 0;

        bool one_in_window = false;

        size_t L = 0;

        for(size_t R = 0; R < nums.size(); R++){
            while(nums[R] == 0 && zero_in_window >= 1){
                // This means that the string is no longer valid
                if(nums[L] == 0){
                    zero_in_window --;
                }
                L++;

                // We move the window to the left until we find a one
            
            }
            if(nums[R] == 1){
                one_in_window = true;
            }else{
                zero_in_window++;
            }
            if(longest_string < R - L&& one_in_window == true){
                longest_string = R - L;
            }
        
        }
        if(one_in_window == false){
            // This means no valid string was found
            return 0;
        }
        return longest_string;
        }
        
};