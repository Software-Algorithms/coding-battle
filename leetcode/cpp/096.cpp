/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/24/2018
 *
 * Data structure:
 *    Binary Search Tree
 *
 * Idea:
 *    - DP.
 *    - 这道题实际上是 Catalan Number卡塔兰数的一个例子，如果对卡塔兰数不熟悉的童鞋可能真不
 *      太好做。
 *    - 可以参考这个讨论：
 *      https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
 *    - Given a sequence 1…n, to construct a Binary Search Tree (BST) out of the
 *      sequence, we could enumerate each number i in the sequence, and use the
 *      number as the root, naturally, the subsequence 1…(i-1) on its left side
 *      would lay on the left branch of the root, and similarly the right
 *      subsequence (i+1)…n lay on the right branch of the root. We then can
 *      construct the subtree from the subsequence recursively. Through the above
 *      approach, we could ensure that the BST that we construct are all unique,
 *      since they have unique roots.
 *    - Procedure:
 *        > we need to define two functions:
 *          G(n): the number of unique BST for a sequence of length n.
 *          F(i, n), 1 <= i <= n: the number of unique BST, where the number i
 *          is the root of BST, and the sequence ranges from 1 to n.
 *        > Initialization: G(0)=1, G(1)=1.
 *        > G(n) = F(1, n) + F(2, n) + ... + F(n, n).
 *        > F(i, n) = G(i-1) * G(n-i)	1 <= i <= n
 *        > Combining the above two:
 *            G(n) = G(0) * G(n-1) + G(1) * G(n-2) + … + G(n-1) * G(0)
 *
 * Complexity:
 *    O(n^2)
 *
 */
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
