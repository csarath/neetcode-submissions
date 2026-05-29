class WordDictionary {
struct TNode {
    std::unordered_map<char, std::unique_ptr<TNode>> child;
    bool end;
    TNode(): end(false){}
};
std::unique_ptr<TNode> root;
bool searchI(TNode* root, std::string_view word) {
    if (word.length() == 0) return root->end;
    if (word[0] != '.') {
        auto it = root->child.find(word[0]);
        if (it == root->child.end()) return false;
        return searchI(it->second.get(), word.substr(1));
    }
    string_view subword = word.substr(1);
    for(auto& ch: root->child) {
        if (searchI(ch.second.get(), subword))
            return true;
    }
    return false;
}
public:
    WordDictionary() {
        root = std::make_unique<TNode>();
    }
    
    void addWord(string word) {
        TNode* head = root.get();
        for (char c: word) {
            auto [it, inserted] = head->child.try_emplace(c, nullptr);
            if (inserted) it->second = std::make_unique<TNode>();
            head = it->second.get();
        }
        head->end = true;
    }
    
    bool search(string word) {
        return searchI(root.get(), word);
    }
};
