class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "0"; // '0' is aynway bigger than a letter

        vector<int> dict(256, 0); // used as a hash table
        vector<bool> visited(256, false);

        // recording numbers of each letters
        // used as a stack
        for(auto c : s) dict[c]++;

        // greedy
        for (auto c : s) {
        	dict[c]--;
        	if(visited[c]) continue;
        	while(c<res.back() && dict[res.back()]) { // later there will be bigger one
        		visited[res.back()] = false;
        		res.pop_back(); // like a stack
        	}
        	res += c;
        	visited[c] = true;
        }

        return res.substr(1);
    }
};
