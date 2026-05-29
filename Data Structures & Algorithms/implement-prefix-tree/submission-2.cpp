#include <cassert>
class PrefixTree {
struct TNode {
    TNode* child;
    bool end;
    TNode(): child(nullptr),end(false) {};
};
TNode* root;
void insert(TNode* root, string_view word) {
    if (word.size() == 0) {
        root->end = true;
        return;
    }
    if (!root->child) {
        root->child = new TNode[26]();
    }
    int idx = word[0] - 'a';
    insert(root->child+idx, word.substr(1));
}
bool search(TNode* root, string_view word, bool prefix = false) {
    if (word.length() == 0){
        return root->end || (prefix && root->child);
    }
    int idx = word[0] - 'a';
    if (root->child) return search(root->child + idx, word.substr(1), prefix);
    return false;
}
public:
    PrefixTree() {
        root = new TNode();
    }
    
    void insert(string word) {
        insert(root, word);
    }
    
    bool search(string word) {
        bool found = search(root, word);
        printf("S found: %d ", found);
        return found;
    }
    
    bool startsWith(string prefix) {
        bool found = search(root, prefix, true);
        printf("P found: %d ", found);
        return found;
    }
};
