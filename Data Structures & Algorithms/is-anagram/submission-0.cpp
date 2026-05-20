class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int count[26] = {0};

        for(auto const & c : s) {
            count[c-'a']++;
        }

        for (auto const & c : t) {
            count[c-'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i]) return false;
        }
        
        return true;
    }
};
