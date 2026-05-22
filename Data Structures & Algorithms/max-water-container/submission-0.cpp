class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        int start = 0;
        int end = heights.size()-1;

        while (start < end) {
            int area = (end-start)*std::min(heights[start], heights[end]);
            res = std::max(res, area);
            if (heights[start] < heights[end]) start++;
            else end--;
        }

        return res;
        
    }
};
