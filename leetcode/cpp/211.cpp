/*
 * Trie
 *
 */

// version 1:
class TrieNode {
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(): isKey(false) {
        memset(children, NULL, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* run = root;
        for (char c : word) {
            if (!(run -> children[c - 'a']))
                run -> children[c - 'a'] = new TrieNode();
            run = run -> children[c - 'a'];
        }
        run -> isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word.c_str(), root);
    }

private:
    TrieNode* root;

    bool query(const char* word, TrieNode* node) {
        TrieNode* run = node;
        for (int i = 0; word[i]; i++) {
            if (run && word[i] != '.')
                run = run -> children[word[i] - 'a'];
            else if (run && word[i] == '.') {
                TrieNode* tmp = run;
                for (int j = 0; j < 26; j++) {
                    run = tmp -> children[j];
                    if (query(word + i + 1, run))
                        return true;
                }
            }
            else break;
        }
        return run && run -> isKey;
    }
};

// version 2: in lintcode
struct TrieNode {
    bool is_end;
    TrieNode* children[26];
    TrieNode() {
        is_end = false;
        memset(children, 0, sizeof(TrieNode*)*26);
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    /*
     * @param word: Adds a word into the data structure.
     * @return: nothing
     */
    void addWord(string &word) {
        // write your code here
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            if(!p->children[word[i]-'a']) p->children[word[i]-'a'] = new TrieNode();
            p = p->children[word[i]-'a'];
        }
        p->is_end = true;
    }

    /*
     * @param word: A word could contain the dot character '.' to represent any one letter.
     * @return: if the word is in the data structure.
     */
    bool search(string &word) {
        // write your code here
        TrieNode* p = root;
        query(word.c_str(), root);
    }
    
private:
    TrieNode* root;
    
    bool query(const char* word, TrieNode* node) {
        TrieNode* p = node;
        for(int i = 0; word[i]; i++) {
            if(word[i] == '.') {
                for(int k = 0; k < 26; k++) {
                    if(p->children[k] && query(word+i+1, p->children[k])) return true;
                }
                return false;
            } else {
                if(!p->children[word[i]-'a']) return false;
                p = p->children[word[i]-'a'];                
            }
        }
        return p->is_end;        
    }
};

// Conclusion:
// 这里处理‘.’的情况还是有一点tricky的：‘.’代表任意的小写字母，这时需要考虑所有可能的情况。26个子树凡存在的都要深度搜索下去，
// 所以需要一个做深度搜索的辅助函数，递归地取得一个贪心解，这个辅助函数需要记住当前子树节点和搜索单词的字符位置，所以这里query
// 函数设置了两个输入变量，一个是字符指针指向单词位置，一个是TrieNode指针指向树种的搜索位置。
//
// memset
// void * memset ( void * ptr, int value, size_t num );
// Fill block of memory
// Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
//
// Reference:
// Grandyang: http://www.cnblogs.com/grandyang/p/4507286.html
// There is a follow-up in the 1st comment.




