
class MedianFinder {
#define printf(...) 
struct TreeNode {
    int val;
    int rank;
    TreeNode* right;
    TreeNode* left;
    TreeNode() = delete;
    explicit TreeNode(int v): val(v), rank(0), right(nullptr), left(nullptr){}
};
private:
    TreeNode* root;
    int size;
    void insert(TreeNode* node, TreeNode** proot) {
        if (!*proot) {
            size++;
            *proot = node;
            return;
        }
        TreeNode* root = *proot;
        if (root->val >= node->val) {
            insert(node, &root->left);
            root->rank++;
        } else {
            insert(node, &root->right);
        }
    }
    int find(TreeNode* root, int k) {
        if (root) {
            printf("search node : %d rank: %d k: %d\n", root->val, root->rank, k);
        } else {
            printf("Invalid NULL node\n");
            return 0;
        }
        if (root->rank == k) return root->val;
        if (root->rank > k) return find(root->left, k);
        else return find(root->right, k-root->rank-1);
    }
    void printTree() {
        std::vector<TreeNode*> next, current;
        next.push_back(root);
        while (!next.empty()) {
            current.swap(next);
            for (auto node: current) {
                if (!node) {
                    printf("(null, null) ");
                    continue;
                }
                printf("(%d %d) ", node->val, node->rank);
                next.push_back(node->left);
                next.push_back(node->right);
            }
            printf("\n");
            current.clear();
        }
    }
public:
    MedianFinder() {
        root = nullptr;
        size = 0;
    }
    
    void addNum(int num) {
        TreeNode* node = new TreeNode(num);
        insert(node, &root);
        printTree();
    }
    
    double findMedian() {
        if (size == 1) {
            return root->val;
        }
        int m = (size-1)/2;
        int n = size/2;
        printf("Computing values at %d and %d (size = %d)\n", m, n,size);
        int val = find(root, m);
        printf("Value at %d is %d\n", m, val);
        if (m != n) {
            int tmp = find(root, n);
            printf("Value at %d is %d\n", n, tmp);
            val += tmp;
            return val/2.0;
        } else {
            return val;
        }

        
    }
};
