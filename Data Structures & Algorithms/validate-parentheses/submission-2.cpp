class Solution {
public:
    bool isValid(string s) {
        std::stack<char> p;
        if (s.size() % 2) return false;
        for (char c : s) {
            if ( c == '{') {
                p.push('}');
            } else if (c == '(') {
                p.push(')');
            } else if (c == '[') {
                p.push(']');
            } else if (p.empty() || p.top() != c) {
                return false;
            } else {
                p.pop();
            }
        }
        return p.empty();
        
    }
};
