class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size()-1;
        int lo = 0;
        while (lo <= hi) {
            int mid = (hi - lo)/2 + lo;
            if (target == nums[mid]) return mid;
            if (nums[mid] >= nums[lo]) {
                if (target < nums[mid] && target >= nums[lo]) {
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            } else {
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
        }
        return -1;
        
    }
};
