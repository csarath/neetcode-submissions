class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size()-1;
        int lo = 0;
        //first find pivot;
        while (lo < hi) {
            int mid = (hi-lo)/2 + lo;
            if (nums[mid] == target) return mid;
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        int pivot = lo;
        std::cout << "Pivot "<< pivot<<std::endl;
        hi = nums.size()-1;
        if (target <= nums[hi]) {
            lo = pivot;
        } else {
            lo = 0;
            hi = pivot-1;
        }
        while (lo <= hi) {
            int mid = (hi-lo)/2+lo;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }

        return -1;
        
    }
};
