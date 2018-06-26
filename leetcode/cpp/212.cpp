/*
 * Trie, DFS
 *
 */

// version 1:
class Trie {
public:
    Trie * children[26];
    bool isLeaf;
    int  wordIdx;
    int prefixCount;

    Trie() {
        isLeaf = false;
        wordIdx = 0;
        prefixCount = 0;
        fill_n(children, 26, nullptr);
    }

    ~Trie() {
        for(auto i=0; i<26; ++i) delete children[i];
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int M, N, wordNum = words.size();
        vector<string> res;
        if( !(M = board.size()) || !(N = board[0].size()) || !wordNum) return res;
        Trie *root = buildTrie(words);
        for(auto i=0; i<M && root->prefixCount; ++i)
            for(auto j=0; j<N; ++j)
                dfs_Trie(res, root, board, words, i, j);
        delete root;
        return res;        
    }
    
private:
    void insertWord(Trie *root,  const vector<string>& words, int idx) {
        int i, childID, len = words[idx].size();
        for(i=0, root->prefixCount++ ; i<len; ++i) {
            childID = words[idx][i]-'a';
            if(!root->children[childID]) root->children[childID] = new Trie();
            root = root->children[childID];
            ++root->prefixCount;
        }
        root->isLeaf = true;
        root->wordIdx = idx;
    }

    Trie *buildTrie(const vector<string> &words) {
        Trie *root = new Trie();
        for(int i=0; i < words.size(); ++i) insertWord(root, words, i);
        return root;
    }

    int dfs_Trie(vector<string> &res, Trie *root, vector<vector<char>>& board, vector<string>& words, int row, int col) {
        int detected = 0;

        if(root->isLeaf) {
            ++detected;
            root->isLeaf = false;
            res.push_back(words[root->wordIdx]);
        }

        if( row<0 || row>=board.size() || col<0 || col>=board[0].size()
           || board[row][col]=='*' || !root->children[ board[row][col]-'a'] 
           || root->children[ board[row][col]-'a']->prefixCount <= 0 ) {
            return detected;
        }
        
        int curC = board[row][col] - 'a';
        board[row][col] = '*';
        detected += dfs_Trie(res, root->children[curC], board, words, row-1, col) +
                    dfs_Trie(res, root->children[curC], board, words, row+1, col) +
                    dfs_Trie(res, root->children[curC], board, words, row, col - 1) +
                    dfs_Trie(res, root->children[curC], board, words, row, col + 1);
        root->prefixCount -= detected;
        board[row][col] = curC + 'a';
        return detected;
    }
};

// version 2:
struct TrieNode {
    TrieNode *child[26];
    string str;
    TrieNode() : str("") {
        for (auto &a : child) a = NULL;
    }
};

struct Trie {
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        TrieNode *p = root;
        for(int i = 0; i < word.length(); i++) {
            int id = word[i] - 'a';
            if(!p->child[id]) p->child[id] = new TrieNode();
            p = p->child[id];
        }
        p->str = word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty() || words.empty()) return {};
        
        Trie t;
        for(int i = 0; i < words.size(); i++) {
            t.insert(words[i]);
        }
        
        vector<string> res;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(t.root->child[board[i][j]-'a']) {
                    search(board, t.root->child[board[i][j]-'a'], i, j, visited, res);
                }
            }
        }
        
        return res;
    }

private:
    void search(vector<vector<char>>& board, TrieNode *node, int i, int j, vector<vector<bool>>& visited, vector<string>& res) {
        if(node->str != "") {
            res.push_back(node->str);
            node->str.clear();
        }
        
        vector<vector<int>> dirs({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        int m = board.size(), n = board[0].size();
        visited[i][j] = true;
        for(int k = 0; k < 4; k++) {
            int x = i + dirs[k][0], y = j + dirs[k][1];
            if(x < 0 || x >= m || y < 0 || y >= n || !node->child[board[x][y]-'a'] || visited[x][y]) continue;
            search(board, node->child[board[x][y]-'a'], x, y, visited, res);
        }
        visited[i][j] = false;
    }
};

// Conclusion:
// 用字典树来求解。那么我们在这题中只要实现字典树中的insert功能就行了，查找单词和前缀就没有必要了，
// 然后DFS的思路跟之前那道 Word Search 词语搜索基本相同。
//
// Reference:
// Grandyang: http://www.cnblogs.com/grandyang/p/4516013.html



