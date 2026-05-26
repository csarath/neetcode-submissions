class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> fMap;
        int maxf = 0;
        int l = 0;
        int start = 0;
        int res = 0;
        for (int end = 0; end < s.size(); end++) {
            fMap[s[end]]++;
            l++;
            maxf = std::max(maxf, fMap[s[end]]);
            while (l - maxf > k) {
                l--;
                fMap[s[start++]]--;
            }
            res = std::max(res, l);
        }
        return res;
    }
};
