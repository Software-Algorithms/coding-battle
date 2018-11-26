class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        result_.clear();
        unordered_map<string, vector<string>> prevMap;
        
        for(auto iter = wordList.begin(); iter != wordList.end(); ++iter) {
            prevMap[*iter] = vector<string>();
        }
        
        vector<unordered_set<string>> candidates(2);
        
        int current = 0;
        int previous = 1;
        
        candidates[current].insert(beginWord);
        
        while(true) {
            current = !current;
            previous = !previous;
            
            for (auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter) {
                wordList.erase(*iter);
            }
            
            candidates[current].clear();
            
            for(auto iter = candidates[previous].begin(); iter != candidates[previous].end(); ++iter) {
                for(size_t pos = 0; pos < iter->size(); ++pos) {
                    string word = *iter;
                    for(int i = 'a'; i <= 'z'; ++i) {
                        if(word[pos] == i){
                            continue;
                        }
                        
                        word[pos] = i;
                        
                        if(wordList.count(word) > 0) {
                            prevMap[word].push_back(*iter);
                            candidates[current].insert(word);
                        }
                    }
                }
            }
            
            if (candidates[current].size() == 0) {
                return result_;
            }
            if (candidates[current].count(endWord)) {
                break;
            }
        }
        
        
        vector<string> path;
        GeneratePath(prevMap, path, endWord);
        
        return result_;
    }
    
private:
    void GeneratePath(unordered_map<string, vector<string>> &prevMap, vector<string>& path,
                      const string& word) {
        if (prevMap[word].size() == 0) {
            path.push_back(word);
            vector<string> curPath = path;
            reverse(curPath.begin(), curPath.end());
            result_.push_back(curPath);
            path.pop_back();
            return;
        }
        
        path.push_back(word);
        for (auto iter = prevMap[word].begin(); iter != prevMap[word].end(); ++iter) {
            GeneratePath(prevMap, path, *iter);
        }
        path.pop_back();
    }
    
    vector<vector<string>> result_;
};
