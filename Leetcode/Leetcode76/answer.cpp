#include <array>
#include <climits>

class Solution {
public:
    std::string minWindow(string s, string t) {
        std::unordered_map<char,int> letters_t;

        if(s.length() < t.length()|| t.length() == 0 || s.length() == 0){
            return "";
        }
        for(char c : t){
            letters_t[c]++;
        }
        
         int needed = t.length();

        size_t minimum_length = INT_MAX;
        size_t left_min = 0,right_min = s.length();
        std::unordered_map<char,int> letters_s;
        int having = 0;
        size_t L = 0;

        for(size_t R = 0; R < s.length(); R ++){
           
            if(having < needed){
                if(letters_t.find(s[R]) != letters_t.end()){
                   letters_s[s[R]]++;

                    if(letters_s[s[R]] <= letters_t[s[R]]){
                        having+= 1;
                    }

                }
            }
                //having >= needed
          
            while(having >= needed){

                if(minimum_length > R - L + 1){
                    minimum_length = R - L + 1;
                    left_min = L;
                    right_min = R;}
                 
                if(letters_t.find(s[L]) != letters_t.end()){
                    letters_s[s[L]] --;

                    if(letters_s[s[L]] < letters_t[s[L]]){
                        having--;
                    }
                }
                 L++;
                        
            }
            }
        if(minimum_length == INT_MAX){
            // In case, the indexes were not updated
            return "";
        }
        std::string result = "";
        for(size_t k = left_min; k < min(right_min + 1,s.length()); k++){
            result += s[k];
        }
        return result;
    }
};
