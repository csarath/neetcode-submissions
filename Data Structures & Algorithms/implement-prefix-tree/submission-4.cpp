#include <cassert>
class PrefixTree {
struct TNode {
    std::unordered_map<char, std::unique_ptr<TNode>> child;
    bool end;
    TNode(): end(false) {};
};
std::unique_ptr<TNode> root;
bool searchI(string_view word, bool prefix = false) {
    TNode* head = root.get();
    for (char c : word) {
        auto it = head->child.find(c);
        if (it == head->child.end()) {
            return false;
        }
        head = it->second.get();
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
            auto [it, inserted] = head->child.try_emplace(c, nullptr);
            if (inserted) {
                it->second = std::make_unique<TNode>();
            }
            head = it->second.get();
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
