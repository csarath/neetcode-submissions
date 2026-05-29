class WordDictionary {
struct TNode {
    std::array<std::unique_ptr<TNode>, 26> childs;
    bool end;
    TNode() : end(false) {}
};
std::unique_ptr<TNode> root;
public:
    WordDictionary() {
        root = std::make_unique<TNode>();
    }
    
    void addWord(string word) {
        TNode* head = root.get();
        for (char c: word) {
            int idx = c - 'a';
            if (!head->childs[idx]) {
                head->childs[idx] = std::make_unique<TNode>();
            }
            head = head->childs[idx].get();
        }
        head->end = true;
    }
    
    bool search(string word) {
        std::stack<std::pair<const TNode*, int>> st;
        st.push({root.get(), 0});

        while(!st.empty()) {
            auto [curr, index] = st.top();
            st.pop();
            if (index == word.length()) {
                if (curr->end)
                    return true;
                continue;
            }

            if (word[index] != '.') {
                int idx = word[index] - 'a';
                if (curr->childs[idx]) {
                    st.push({curr->childs[idx].get(), index+1});
                }
            } else {
                for(int idx = 0; idx < 26; idx++) {
                    if (curr->childs[idx])
                        st.push({curr->childs[idx].get(), index+1});
                }
            }
        }

        return false;
    }
};
