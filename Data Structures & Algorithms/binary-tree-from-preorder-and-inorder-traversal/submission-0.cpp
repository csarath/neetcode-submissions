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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, std::pair<int,int> pIndex, std::pair<int,int> iIndex) {
        if (pIndex.first == pIndex.second) {
            return new TreeNode(preorder[pIndex.first]);
        } else if (pIndex.first > pIndex.second) {
            return nullptr;
        }
        int rootVal = preorder[pIndex.first];
        int i = iIndex.first;
        for (;; i++) {
            if (inorder[i] == rootVal) break;
        }
        int lSize = i - iIndex.first;
        TreeNode* root = new TreeNode(rootVal);

        root->left = buildTree(preorder, inorder, {pIndex.first+1, pIndex.first+lSize}, {iIndex.first, i-1});
        root->right = buildTree(preorder, inorder, {pIndex.first+lSize+1, pIndex.second}, {i+1, iIndex.second});

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return buildTree(preorder, inorder, {0,preorder.size()-1}, {0, inorder.size()-1});
    }
};
