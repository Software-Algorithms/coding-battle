class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        if(words.size() == 0) return ret;

        int idx = 0;
        while(idx < words.size()) {
        	// get current line
        	int end = idx;
        	int total = 0;
        	vector<string> line;
        	while( end < words.size() && (total + words[end].length() + line.size() <= maxWidth) ) {
        		line.push_back(words[end]);
        		total += words[end].length();
        		end++;
        	}

        	// process the current line into string
        	// two cases:
        	// (1) last line or one-single-word line
        	// (2) regular line --> evenly distribute spaces
        	string str = words[idx]; // at least one word
        	if( (end == words.size()) || (line.size() == 1)) {
        		for(int i = idx+1; i<end; i++) {
        			str += " " + words[i];
        		}
        		str += string(maxWidth - (total+line.size()-1),' ');
        	} else {
        		int nspaces = maxWidth - total;
        		int remains = nspaces % (line.size()-1);
        		int base = nspaces / (line.size()-1);
        		for(int i = idx+1; i<end; i++) {
        			str += string(base, ' ');
        			if(remains > 0) {
        				str += " ";
        				remains--;
        			}
        			str += words[i];
        		}
        	}

        	ret.push_back(str);
        	idx = end;
        }

        return ret;
    }
};