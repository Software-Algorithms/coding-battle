/*
 * Math, Hash Table
 *
 * C++ Solution
 *
 */
class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> passed(n, false);
        int sum = 1;
        int upper = sqrt(n);
        for (int i=3; i<n; i+=2) {
            if (!passed[i]) {
                sum++;
                //avoid overflow
                if (i>upper) continue;
                for (int j=i*i; j<n; j+=i) {
                    passed[j] = true;
                }
            }
        }
        return sum;
    }
};

/*
 * Math, Hash Table
 *
 * C / C++ Solution
 *
 * 1. trick1 is to use square root of n.
 * 2. trick2 is not to use non-prime numbers as the step
 * 3. trick3 is to use i*i as the start.
 * 4. trick4 is to use count-- in every loop, avoiding another traversal.
 */
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        if(n == 3) return 1;
        bool *prime= (bool*)malloc(sizeof(bool)*n);
        int i=0,j=0;
        int count = n-2;
        int rt = sqrt(n);//trick1
        for(j = 0; j < n; j++)
        {
            prime[j] = 1;
        }
        for(i = 2; i <= rt; i++)
        {
             if (prime[i])//trick2
            {
                for(j=i*i ; j<n ; j+=i)//trick3
                {
                    if (prime[j])
                            {
                               prime[j]=0;
                               count--;//trick4
                            }
                }
            }
        }
        free(prime);
        return count;
    }
};
