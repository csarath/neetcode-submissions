class WordDictionary {
struct TNode {
    std::unordered_map<char, std::unique_ptr<TNode>> child;
    bool end;
    TNode(): end(false){}
};
std::unique_ptr<TNode> root;
bool searchI(TNode* root, const std::string_view& word, int index) {
    if (word.length() == index) return root->end;
    if (word[index] != '.') {
        auto it = root->child.find(word[index]);
        if (it == root->child.end()) return false;
        return searchI(it->second.get(), word, index+1);
    }
    for(auto& ch: root->child) {
        if (searchI(ch.second.get(), word, index+1))
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
        return searchI(root.get(), word, 0);
    }
};
