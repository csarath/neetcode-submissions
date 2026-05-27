class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size()-1;
        int n = nums.size();

        while (lo < hi) {
            int mid = (hi-lo)/2 + lo;
            if ((mid == 0 || nums[mid] < nums[mid-1]) 
                && (mid == n-1 || nums[mid] < nums[mid+1]))
                return nums[mid];
            if (nums[mid] < nums[hi]) hi = mid-1;
            else lo = mid+1;
        }
        return nums[lo];
        
    }
};
