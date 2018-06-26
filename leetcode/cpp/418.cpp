/*
 *
 *
 */
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (const auto& sen : sentence) {
            s += sen;
            s += " ";
        }
        
        int count{0};
        int n = s.size();
        for (int i = 0; i < rows; ++i) {
            count += cols;
            if (s[count % n] == ' ') {
                ++count;
            } else {
                while (count > 0 && s[(count - 1) % n] != ' ')
                    --count;
            }
        }
        
        return count / n;      
    }
};

// Conclusion:
// 
// Reference:
// 
