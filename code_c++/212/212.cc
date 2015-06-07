class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < 26; i ++)
            next[i] = NULL;
        flag = 0;
    }
    TrieNode *next[26];
    int flag = 0;
};
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    TrieNode *getRoot() {
        return root;
    }
    // Inserts a word into the trie.
    void insert(string s) {
       TrieNode *p = root;
       for (int i = 0; i < s.size(); i ++) {
           if ((p->next)[s[i] - 'a'] == NULL) {
               (p->next)[s[i] - 'a'] = new TrieNode();
           }
           p = (p->next)[s[i] - 'a'];
           if (i == s.size() - 1)
              p->flag = 1;  
       } 
    }
private:
    TrieNode* root;
};
class Solution {
public:
    vector<string> ret;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<int> > record(board.size(), vector<int>(board[0].size(), 0));
        Trie t;
        for (int i = 0; i < words.size(); i ++)
            t.insert(words[i]);
        TrieNode * root = t.getRoot();
        for (int i = 0; i < board.size(); i ++)
            for (int j = 0; j < board[0].size(); j ++)
                backTrace(root, record, board, i, j, "");
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
    void backTrace(TrieNode *root, vector<vector<int> > &record, vector<vector<char> >& board, int i, int j, string str) {
        if (root == NULL)
            return ;
        for (int k = 0; k < 26; k ++) {
            TrieNode *p = root->next[k];
            if (p == NULL)
                continue;
            char ch = 'a' + k;
            if (ch != board[i][j])
                continue;
            record[i][j] = 1;
            if (p->flag == 1) {
                ret.push_back(str + ch);
            //    return ;
            }
            if (i - 1 >= 0 && record[i - 1][j] == 0) {      // up
                backTrace(p, record, board, i - 1, j, str + ch);
            }
            if (i + 1 < board.size() && record[i + 1][j] == 0) {     // down
                backTrace(p, record, board, i + 1, j, str + ch);
            }
            if (j - 1 >= 0 && record[i][j - 1] == 0) {       // left
                backTrace(p, record, board, i, j - 1, str + ch);
            }
            if (j + 1 < board[0].size() && record[i][j + 1] == 0) {      // right
                backTrace(p, record, board, i, j + 1, str + ch);
            }
            record[i][j] = 0;
        }
    }
};
