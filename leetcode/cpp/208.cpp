/*
 * Trie, Design
 *
 */
class TrieNode {
public:
    TrieNode *next[26];
    bool is_end;

    // Initialize your data structure here.
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_end = b;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size(); ++i) {
            if(p->next[word[i] - 'a'] == NULL)
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.size() && p != NULL; ++i) {
            p = p->next[word[i] - 'a'];
        }
        return p != NULL && p->is_end;        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(int i = 0; i < prefix.size() && p != NULL; ++i) {
            p = p->next[prefix[i] - 'a'];
        }
        return p != NULL;
    }

private:
    TrieNode *root;
};

// Conclusion:
// You understand Trie, you solve it.


// version 2: in lintcode
struct TrieNode {
    bool is_end;
    TrieNode* children[26];
    TrieNode() {
        is_end = false;
        memset(children, NULL, sizeof(TrieNode* )*26);
    }
};

class Trie {
public:
    Trie() {
        // do intialization if necessary
        root = new TrieNode();
    }

    /*
     * @param word: a word
     * @return: nothing
     */
    void insert(string &word) {
        // write your code here
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            if(!p->children[word[i]-'a']) p->children[word[i]-'a'] = new TrieNode();
            p = p->children[word[i]-'a'];
        }
        p->is_end = true;
    }

    /*
     * @param word: A string
     * @return: if the word is in the trie.
     */
    bool search(string &word) {
        // write your code here
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            if(!p->children[word[i]-'a']) return false;
            p = p->children[word[i]-'a'];
        }
        return p->is_end;
    }

    /*
     * @param prefix: A string
     * @return: if there is any word in the trie that starts with the given prefix.
     */
    bool startsWith(string &prefix) {
        // write your code here
        TrieNode* p = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(!p->children[prefix[i]-'a']) return false;
            p = p->children[prefix[i]-'a'];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

// Conclusion:
// memset(pos, val, capacity); // it is a c styled coding




