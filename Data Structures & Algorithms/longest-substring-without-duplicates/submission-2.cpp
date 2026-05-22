class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::array<int, 128> charMap;
        charMap.fill(-1);
    
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (charMap[s[i]] >= start) {
                start = charMap[s[i]] + 1;
            }
            charMap[s[i]] = i;
            maxLength = std::max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};
