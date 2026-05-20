class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_product(nums.size(), 0);
        prefix_product[0] = 1;
        for (int i =1; i < nums.size(); i++) {
            prefix_product[i] = prefix_product[i-1]*nums[i-1];
        }
        vector<int> res(nums.size(), 0);
        int suffix_product = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            res[i] = suffix_product*prefix_product[i];
            suffix_product *= nums[i];
        }
        return res;
    }
};
