class Solution {
public:

    int getParent (const unordered_map<int, int>& parentMap, int i) {
            auto it = parentMap.find(i);
            //it should exist.
            if (it->second == i) return i;
            return getParent(parentMap, it->second);
    };
    int longestConsecutive(vector<int>& nums) {

        
        //std::unordered_set<int> visited;
        std::unordered_map<int, int> parentMap;

        

        for (auto i: nums) {
            if (parentMap.find(i) != parentMap.end()) continue;//ignore duplicates
            int parent = i;
            auto it = parentMap.find(i-1);
            if (it != parentMap.end()) {
                parent = it->second;
            }
            it = parentMap.find(i+1);
            if (it != parentMap.end()){
                it->second = parent;
            }
            parentMap[i] = parent;
        }
        /*std::cout << "{ ";
        for(auto const & it : parentMap) {
            std::cout<< it.first << " : " << it.second << std::endl;
        }
        std::cout << "}";*/
        unordered_map<int, int> count;
        int res = 0;
        for (auto & it : parentMap) {
            it.second = getParent(parentMap, it.second);
            cout << it.first << " -> " << it.second << endl;
            if (count.find(it.second) == count.end()) count[it.second] = 1;
            else count[it.second]++;
            if (res < count[it.second]) res = count[it.second];
        }
        return res;

        
    }
};
