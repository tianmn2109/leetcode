class TrieTree {
public:
    TrieTree *next[26];
    bool flag;
    TrieTree() {
        for (int i = 0; i < 26; i ++)
            next[i] = NULL;
        flag = 0;
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieTree();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieTree *p = root;
        for (int i = 0; i < word.size(); i ++) {
            if ((p->next)[word[i] - 'a'] == NULL) {
                (p->next)[word[i] - 'a'] = new TrieTree();
            }
            p = (p->next)[word[i] - 'a'];
            if (i == word.size() - 1)
                p->flag = 1;
        }
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool searchAux(string word, TrieTree *root) {
        if (word.size() == 0 && root->flag == 1)
            return true;
        TrieTree *p = root;
        for (int i = 0; i < word.size(); i ++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j ++) {
                    if ((p->next)[j] != NULL && searchAux(word.substr(i + 1), (p->next)[j]))
                        return true;
                }
                return false;
            }   
            else if ((p->next)[word[i] - 'a'] != NULL){
                p = (p->next)[word[i] - 'a'];
            }
            else
                return false;
            if (i == word.size() - 1 && p->flag == 1)
                return true;
        }
        return false;
    }
    bool search(string word) {
        return searchAux(word, root);
    }
private:
    TrieTree * root;
};
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
