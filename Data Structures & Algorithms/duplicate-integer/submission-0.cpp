class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> visited;

        for (auto const &i : nums) {
            if (visited.count(i)) return true;
            visited.insert(i);
        }
        
        return false;
    }
};