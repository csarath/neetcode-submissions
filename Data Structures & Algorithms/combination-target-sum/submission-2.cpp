class Solution {
public:
    void backtrack(vector<int>& nums, int idx, int target, vector<vector<int>>& res, vector<int>& state) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(state);
            return;
        } else if (idx >= nums.size()) {
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            state.push_back(nums[i]);
            backtrack(nums, i, target - nums[i], res, state);
            state.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> state;
        backtrack(nums, 0, target, res, state);
        return res;
    }
};
