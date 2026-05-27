/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    std::unordered_map<int, int> iMap;
    
    TreeNode* buildTree(vector<int>::iterator& pIt, std::pair<int,int> iIndex) {
        if (iIndex.first > iIndex.second) {
            return nullptr;
        }
        int rootVal = *pIt++;
        int i = iMap[rootVal];
        TreeNode* root = new TreeNode(rootVal);

        root->left = buildTree(pIt, {iIndex.first, i-1});
        root->right = buildTree(pIt, {i+1, iIndex.second});

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        iMap.reserve(inorder.size());
        for(int i = 0; i < inorder.size(); i++) {
            iMap[inorder[i]] = i;
        }
        auto pIt = preorder.begin();
        return buildTree(pIt, {0, inorder.size()-1});
    }
};
