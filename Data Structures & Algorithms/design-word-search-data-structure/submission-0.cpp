class WordDictionary {
struct TNode {
    std::array<std::unique_ptr<TNode>, 26> child;
    bool end;
    TNode(): end(false){}
};
std::unique_ptr<TNode> root;
bool searchI(TNode* root, std::string_view word) {
    if (word.length() == 0) return root->end;
    if (word[0] != '.') {
        int idx = word[0] - 'a';
        if (!root->child[idx]) return false;
        return searchI(root->child[idx].get(), word.substr(1));
    }
    string_view subword = word.substr(1);
    for(int i = 0; i < 26; i++) {
        if (root->child[i] && searchI(root->child[i].get(), subword))
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
            int idx = c - 'a';
            if (!head->child[idx]) head->child[idx] = std::make_unique<TNode>();
            head = head->child[idx].get();
        }
        head->end = true;
    }
    
    bool search(string word) {
        return searchI(root.get(), word);
    }
};
