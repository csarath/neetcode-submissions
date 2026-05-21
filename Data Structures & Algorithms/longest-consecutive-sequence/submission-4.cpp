class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int result = 0;
        for (auto i : numSet) {
            if (numSet.find(i-1) != numSet.end()) continue;
            int length = 1;
            while (numSet.find(++i) != numSet.end()) length++;
            result = std::max(result, length);
        }
        return result;
    }
};
