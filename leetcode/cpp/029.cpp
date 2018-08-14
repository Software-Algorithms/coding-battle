/*
 * Math, Binary Search
 *
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
 
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
 
        long long res = 0;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        while(dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res;          
    }
};


/*****
小结（Conclusion）：
除法的实现，有二分的思想在里面，简单的说就是一半一半地减去。要烂熟，不妨先强行记忆。

思路(Idea)：
1. 处理edge cases: divisor == 0 不可除
                  dividend == INT_MIN && divisor == -1， result = -INT_MIN > INT_MAX 会溢出
2. 确定符号，留下绝对值作处理
3. 防止溢出用long long type
4. 主循环：作减法和倍乘
		  除数（dvd）比被除数大（dvs），则对被除数连续作倍乘（记录为temp），同时记录倍数（multiple），最后倍数加入结果（res）；
		  除数更新为dvd = dvd - temp，继续上面的步骤，直到除数（dvd）小于被除数（dvs）。
5. 最后返回结果，记得要加上符号。

要点(Take-away)：
> In c++:
  INT_MIN	Minimum value for a variable of type int .	–2147483647 – 1
  INT_MAX	Maximum value for a variable of type int .	2147483647
> 异或（"^"）: 两项条件一个真一个假则为真，两项都为真或都为假则为假。
*****/

