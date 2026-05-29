#include <cassert>
class PrefixTree {
struct TNode {
    std::array<std::unique_ptr<TNode>, 26> child;
    bool end;
    TNode(): end(false) {};
};
std::unique_ptr<TNode> root;
bool searchI(string_view word, bool prefix = false) {
    TNode* head = root.get();
    for (char c : word) {
        int idx = c - 'a';
        if (!head->child[idx])
            return false;
        head = head->child[idx].get();
    }
    return head->end || prefix;
}
public:
    PrefixTree() {
        root = std::make_unique<TNode>();
    }
    
    void insert(string word) {
        TNode* head = root.get();
        for (char c : word) {
            int idx = c - 'a';
            if (head->child[idx] == nullptr)
                head->child[idx] = std::make_unique<TNode>();
            head = head->child[idx].get();
        }
        head->end = true;
    }
    
    bool search(string word) {
        bool found = searchI(word);
        return found;
    }
    
    bool startsWith(string prefix) {
        bool found = searchI(prefix, true);
        return found;
    }
};
