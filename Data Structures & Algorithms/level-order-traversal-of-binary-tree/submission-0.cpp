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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> next;
        vector<TreeNode*> current;
        if (root)
            next.push_back(root);
        vector<vector<int>> res;
        while (next.size()) {
            current.swap(next);
            vector<int> level;
            for (auto const &node: current) {
                level.push_back(node->val);
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            current.clear();
            res.push_back(std::move(level));
        }
        return res;
    }
};
