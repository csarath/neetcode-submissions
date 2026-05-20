class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;

        for (int i: nums) {
            count[i]++;
        }

        std::vector<std::vector<int>> buckets(nums.size()+1);

        for (auto const& it: count) {
            buckets[it.second].push_back(it.first);
        }

        std::vector<int> result;
        result.reserve(k);
        
        for (int i = buckets.size()-1; i >= 0 && result.size() < k; --i) {
            if (!buckets[i].empty()) {
                for (int num : buckets[i]) {
                    result.push_back(num);
                    if (result.size() == k) {
                        break;
                    }
                }
            }
        }
        return result;
    }
};
