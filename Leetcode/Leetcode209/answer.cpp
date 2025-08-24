#include <climits>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int minimum_length = INT_MAX;
        // Index used as left bound for the window
        int L = 0;
        int cur_sum = 0;

        for(size_t R  = 0; R < nums.size(); R++){
            
            while(cur_sum + nums[R] >= target){
                // This means that we are in a valid window so we check their length
                if(R - L + 1 < minimum_length){
                    minimum_length = R - L + 1;
                }
                // We update the sum and L accordingly
                cur_sum -= nums[L];
                L++;
            }
            // We add the new right element
            cur_sum +=nums[R];

        }
        if(minimum_length == INT_MAX){
            return 0;
        }
        
        return minimum_length;
    }
};
