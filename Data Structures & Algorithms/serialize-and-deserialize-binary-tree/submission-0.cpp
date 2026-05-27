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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) return res;
        std::vector<TreeNode*> current;
        std::vector<TreeNode*> next;
        next.push_back(root);
        while (!next.empty()) {
            current.swap(next);
            for (auto & node: current) {
                if (node) {
                    unsigned int val = node->val+1001;
                    unsigned char first = val;
                    unsigned char second = val >> 8;
                    res.push_back(first);
                    res.push_back(second);
                    next.push_back(node->left);
                    next.push_back(node->right);
                } else {
                    res.push_back(0);
                    res.push_back(0);
                }
            }
            current.clear();
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        std::vector<TreeNode*> nodes;
        for (int i = 0; i < data.size(); i+=2) {
            unsigned char c1 = data[i];
            unsigned char c2 = data[i+1];
            int val = c2 << 8 | c1;

            if (!val) nodes.push_back(nullptr);
            else nodes.push_back(new TreeNode(val - 1001));
        }
        
        TreeNode* root = nullptr;
        std::vector<TreeNode**> next;
        std::vector<TreeNode**> current;
        next.push_back(&root);
        int idx = 0;
        while (!next.empty()) {
            current.swap(next);
            for(auto &pnode : current) {
                *pnode = nodes[idx++];
                if (*pnode) {
                    next.push_back(&((*pnode)->left));
                    next.push_back(&((*pnode)->right));
                }
            }
            current.clear();
        }
        return root;
    }
};
