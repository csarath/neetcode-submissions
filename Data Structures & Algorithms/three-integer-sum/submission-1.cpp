#include <vector>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (i > 0) if (nums[i] == nums[i-1]) continue;
            //std::cout << "Check for " << nums[i] <<endl;
            int target = -nums[i];
            int start = i+1;
            int end = n-1;
            while (start < end) {
                //std::cout << "\tchecking " << nums[start] << " " << nums[end] << std::endl;
                if (nums[start] + nums[end] == target) {
                    //std::cout << "\t\tFound match\n";
                    res.push_back({nums[i], nums[start], nums[end]});
                    while (start < end && nums[start] == nums[start+1]) start++;
                    while (start < end && nums[end] == nums[end-1]) end--;
                }
                if (start < end) {
                    if (nums[start] + nums[end] < target) start++;
                    else end--;
                }
            }
        }
        return res;
        
    }
};
