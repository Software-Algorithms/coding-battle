/*
 * Solution 1:
 * Stack, Hash Table, Greedy
 *
 */
// version 1:
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

// version 2:
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[256] = {0}, visited[256] = {0};
        string res = "0";
        for (auto a : s) ++m[a];
        for (auto a : s) {
            --m[a];
            if (visited[a]) continue;
            while (a < res.back() && m[res.back()]) {
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += a;
            visited[a] = 1;
        }
        return res.substr(1);
    }
};

// Conclusion:
// 首先题意先理解：这道题让我们移除重复字母，使得每个字符只能出现一次，而且结果要按字母顺序排，前提是不能打乱其原本的相对位置。
// 1) 建立一个哈希表来统计每个字母出现的次数，还需要一个visited数字来纪录每个字母是否被访问过。
// 2) 遍历整个字符串，对于遍历到的字符，先在哈希表中将其值减1，然后看visited中是否被访问过，若访问过则继续循环，说明该字母已
// 经出现在结果中并且位置已经安排妥当。如果没访问过，我们和结果中最后一个字母比较，如果该字母的ASCII码小并且结果中的最后一个字
// 母在哈希表中的值不为0(说明后面还会出现这个字母)，那么我们此时就要在结果中删去最后一个字母且将其标记为未访问，然后加上当前遍
// 历到的字母，并且将其标记为已访问，以此类推直至遍历完整个字符串s，此时结果里的字符串即为所求。这里有个小技巧，我们一开始给结
// 果字符串res中放个"0"，就是为了在第一次比较时方便，如果为空就没法和res中的最后一个字符比较了，而‘0’的ASCII码要小于任意一个
// 字母的，所以不会有问题。最后我们返回结果时再去掉开头那个‘0’即可。
//
// 回过来再看这道题，要删除重复字母，又不能改变原有顺序，那么问题也就是要解决如何在不同位置上的重复字母取舍。hash表的作用是记
// 录字母的出现次数，用来判定同样字母后面还会不会见到。是用来增加信息能见度的。visited作为标志位，记录是否已放置到位。
// （1）如果当前结果最后字母是仅存的，那么必然留在结果中。
// （2）如果当前字母值小于结果中最后的字母，那么也无须判定，直接加之于结果之后就是符合题意的。
// （3）只有前面两个条件均不满足，才要从结果中弹出最后一个字母，这就类似于stack的操作，不过是由string实现的。


