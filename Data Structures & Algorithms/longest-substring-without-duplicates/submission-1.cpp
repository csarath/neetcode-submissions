class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> charM;
        int res = 0;
        int start = 0;
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            //std::printf("Currently between %c and %c and length is %d\n",s[start], s[i], len);
            if(charM.find(s[i]) == charM.end()) {
                len++;
                charM[s[i]] = i;
            } else {
                res = max(len, res);
                start = max(start, charM[s[i]]+1);
                len = i-start+1;
                charM[s[i]] = i;
            }
        }
        res = max(len, res);
        return res;
        
    }
};
