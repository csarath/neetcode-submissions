class Solution {
public:
    string minWindow(string s, string t) {
        auto getIndex = [](const char& c) -> int {
            if ('a' <= c && c <= 'z') return c - 'a';
            else return 26+c-'A';
        };
        if (s.size() < t.size()) return "";
        std::unordered_map<char, int> rmap;
        int tfrq[52] = {0};
        int sfrq[52] = {0};
        for (char c: t) {
            tfrq[getIndex(c)]++;
            rmap[c]++;
        }
        string res = s;
        int start = 0, end = 0;
        while (end < s.size()) {
            //std::cout << "Start = "<< start << " End = "<<end << endl;
            auto it = rmap.find(s[end]);
            if (it != rmap.end()) {
                it->second--;
                if (it->second == 0) {
                    rmap.erase(s[end]);
                }
            }
            sfrq[getIndex(s[end])]++;
            while (start < end && sfrq[getIndex(s[start])] > tfrq[getIndex(s[start])]) {
                sfrq[getIndex(s[start++])]--;
            }
            if (rmap.size() == 0 && res.size() > end-start+1) {
                res = s.substr(start,end-start+1);
            }
            end++;
        }
        if (rmap.size() != 0) {
            return "";
        }
        return res;

        
    }
};
