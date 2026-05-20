class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            auto it = numMap.find(target-current);
            if (it != numMap.end()) {
                return {it->second, i}; 
            }
            numMap[current] = i;
        }
        return {-1, -1};
    }
};
