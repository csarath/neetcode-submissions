class Solution {
public:
    void backtrack(vector<int>& nums, int idx, int target, vector<vector<int>>& res, vector<int>& state) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            /*std::printf("FOUND!!: state: {");
            std::for_each(state.begin(), state.end(), [](auto &n) {std::printf("%d, ", n);});
            std::printf("} idx: %d\n", idx);*/
            res.push_back(state);
            return;
        } else if (idx >= nums.size()) {
            return;
        }
        /*std::printf("state: {");
        std::for_each(state.begin(), state.end(), [](auto &n) {std::printf("%d, ", n);});
        std::printf("} idx: %d\n", idx);*/
        state.push_back(nums[idx]);
        backtrack(nums, idx, target - nums[idx], res, state);
        state.pop_back();
        backtrack(nums, idx+1, target, res, state);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> state;
        //for (int i = 0; i < nums.size(); i++) {
        //    state.clear();
            backtrack(nums, 0, target, res, state);
        //}
        return res;
    }
};
