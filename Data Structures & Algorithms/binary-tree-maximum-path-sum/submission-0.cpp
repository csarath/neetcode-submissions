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
    int maxPathSum(TreeNode* root, int& res) {
        if (!root) return INT_MIN;
        int lval = maxPathSum(root->left, res);
        int rval = maxPathSum(root->right, res);
        int tmp = root->val;
        tmp += std::max(0, lval);
        tmp += std::max(0, rval);
        res = std::max(res, tmp);
        /*if (res == tmp) {
            cout << "Max " << res <<  " at " << root->val << std::endl;
        }*/
        return root->val + std::max(0, std::max(lval, rval));
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }
};
