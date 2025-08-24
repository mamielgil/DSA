class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        using namespace std;
        unordered_map<string,int> substrings;
        vector<string> result = {};

        if(s.size() < 10){
            return result;
        }

        // We take the first substring and store it in the map
        substrings[s.substr(0,10)] = 1;
        int L = 0;
        for(size_t R = 10; R < s.size(); R++){
            L++;
            substrings[s.substr(L,10)] += 1;
        }

        // Now that we have stored the number of occurences for each substring, we only save
        // in the result vector the ones that appear more than once

        for(pair<const string, int> element: substrings){
            if(element.second > 1){
                result.push_back(element.first);
            }
        }

        return result;

    }
};
