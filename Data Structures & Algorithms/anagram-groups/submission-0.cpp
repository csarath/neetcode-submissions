class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> strMap;
    
        for (auto const& str : strs) {
            int counts[26] = {0}; // Fixed initialization syntax
            for (auto const& c : str) {
                counts[c - 'a']++;
            }
            
            string key;
            for (int i = 0; i < 26; i++) {
                key += std::to_string(counts[i]) + '#';
            }
            strMap[key].emplace_back(str);
        }
        
        vector<vector<string>> result;
        result.reserve(strMap.size());
        
        // REMOVED 'const' here so std::move can actually transfer ownership
        for (auto &it : strMap) { 
            result.push_back(std::move(it.second));
        }
        
        return result;
    }
};
