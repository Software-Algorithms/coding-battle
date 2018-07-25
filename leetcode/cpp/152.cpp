/*
 * DP
 *
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int imax = nums[0], imin = nums[0];
        int max_pro = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] < 0) {
                swap(imax, imin);
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            max_pro = max(max_pro, imax);
        }
        return max_pro;
    }
};

// Conclusion:
// 做题之前，还是有必要把所有情况在草稿纸上画一遍，这样基本上不会有遗漏。
// 比如说这里，对于结尾在nums[i]的数组而言，到底是取nums[i]还是其与之前结果的乘积作为最值，
// 靠心算是比较乱的，如果写下来各种情况，就比较清楚了，那么之后再写条件从句也是易如反掌。
// 具体如下：
// 这里大致上继承了之前求 maxSum 的题目的思想，只看结束于当前元素的子数列。比之前更为复杂的情
// 况是，这里有 0 或者 负值 存在，最大值和最小值是在轮换的，所以必须同时记录两个动态规划数组或
// 变量（这里是用的imax和imin）。
// 假设 nums[i] > 0 :
// imax 可能是 imax * nums[i] 或者 nums[i]，
// 同理，imin 可能是 imin * nums[i] 或者 nums[i]，
// 这取决于 imax 和 imin 的正负性。最简单的处理就是用 max 和 min 一概而论。
// nums[i] = 0 的情况把可以做相同处理。
// nums[i] < 0 的情况把 imax 和 imin 交换即可。





