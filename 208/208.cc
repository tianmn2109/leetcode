#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < 26; i ++)
            next[i] = NULL;
        flag = 0;
    }
    TrieNode *next[26];
    int flag;
};
class Trie {
public:
    Trie() {
        root = new TrieNode();
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
    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *p = root;
        for (int i = 0; p != NULL && i < key.size(); i ++) {
            p = (p->next)[key[i] - 'a'];
        }
        if (p == NULL)
            return false;
        if (p->flag != 1)
            return false;
        return true;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (int i = 0; p != NULL && i < prefix.size(); i ++) {
            p = (p->next)[prefix[i] - 'a'];
        }
        if (p == NULL)
            return false;
        return true;
    }
private:
    TrieNode* root;
};
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
int main()
{
	Trie tree;
	tree.insert("a");
	tree.search("a");
	tree.startsWith("a");
	return 0;
}
