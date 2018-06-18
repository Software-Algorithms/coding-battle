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
class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode() : str("") {
            for (auto &a : child) a = NULL;
        }
    };
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &a : words) T.insert(a);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (T.root->child[board[i][j] - 'a']) {
                    search(board, T.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }
    void search(vector<vector<char> > &board, TrieNode *p, int i, int j, vector<vector<bool> > &visit, vector<string> &res) { 
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;
    }
};

// Conclusion:
// 用字典树来求解。那么我们在这题中只要实现字典树中的insert功能就行了，查找单词和前缀就没有必要了，
// 然后DFS的思路跟之前那道 Word Search 词语搜索基本相同。
//
// Reference:
// Grandyang: http://www.cnblogs.com/grandyang/p/4516013.html



