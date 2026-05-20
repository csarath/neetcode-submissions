class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto const& str: strs) {
            unsigned char len = static_cast<unsigned char>(str.length()); //< 200. Should fit in 8-bits.
            res += (char)len + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        if (s.size() == 1) { //Can't be zero
            return {""};
        }
        int idx = 0;
        std::vector<std::string> result;
        while (idx < s.size()) {
            unsigned char len = s[idx];
            result.push_back(s.substr(idx+1, len));
            idx += len+1;
        }
        return result;
    }
};
