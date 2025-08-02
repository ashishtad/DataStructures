

#include <string>

/*
    Trie implementation.
*/

struct TrieNode {
    TrieNode *children[26];
    bool isend;
    TrieNode() {
        isend = false;
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {

    TrieNode *root;
    public:
    Trie() {
        root = new TrieNode();
    }
    /* Insrt a word in Trie */
    void insert(const std::string &word) {
        if (word.empty()) return;
        TrieNode *curNode = root;
        for (char ch : word) {
            if (!curNode->children[ch-'a']) curNode->children[ch-'a'] = new TrieNode(); 
            curNode = curNode->children[ch-'a'];
        }
        curNode->isend = true;
    }
    /* Search a word in Trie */
    bool search(const std::string &word) {
        if (word.empty()) return false;
        TrieNode *node = root;
        for (char ch: word) {
            if (!node->children[ch-'a']) return false;
            node = node->children[ch-'a'];
        }
        return node->isend;
    }
    /* Check if a prefix(starts with )  */
    bool startsWith(const std::string &prefix) {
        TrieNode *node = root;
        for(char ch: prefix) {
            if (!node->children[ch-'a']) return false;
            node = node->children[ch-'a'];
        }
        return true;
    }
};