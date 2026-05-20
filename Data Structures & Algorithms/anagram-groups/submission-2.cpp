class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>hash;
        for(string s:strs){
            vector<int>freq(26 , 0);
            for(char ch:s){
                freq[ch-'a']++;
            }
            string key = "";
            for(int i=0;i<26;i++){
                key+='#'+freq[i];
            }

            hash[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto& [s , lst]:hash){
            ans.push_back(lst);
        }
        return ans;
    }
};
