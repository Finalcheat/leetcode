/**
 * @file Palindrome-Number.cpp
 * @brief 回文数(https://leetcode.com/problems/palindrome-number/) 
 * @author Finalcheat
 * @date 2016-05-28
 */

/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 */

/**
 * 反转数字，然后判断是否相等即可。
 */

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            }
            int reverseNum = 0;
            int num = x;
            while (num) {
                const int n = num % 10;
                reverseNum = reverseNum * 10 + n;
                num = num / 10;
            }
            return reverseNum == x;
        }
};
