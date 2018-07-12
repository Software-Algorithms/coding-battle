// C++ program of finding nth palindrome of k digit

#include <iostream>
#include <math.h>

using namespace std;
 
int nthPalindrome(int n, int k) {
    // Determine the first half digits
    int temp = (k & 1) ? (k / 2) : (k/2 - 1);
    int palindrome = (int)pow(10, temp);
    palindrome += n - 1;
 
    int reversed = palindrome;
 
    // If k is odd, truncate the last digit
    if (k & 1) reversed /= 10;
 
    // print the last half digits of palindrome
    while (reversed) {
        palindrome = palindrome * 10 + reversed % 10;
        reversed /= 10;
    }

    return palindrome;
}
 
// Driver code
int main() {
    int n = 6, k = 5;
    cout << nthPalindrome(n ,k) << endl;
 
    n = 10, k = 6;
    cout << nthPalindrome(n, k) << endl;
    return 0;
}
