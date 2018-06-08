/**
 * @file Integer-to-Roman.cpp
 * @brief 阿拉伯数字转罗马数字(https://leetcode.com/problems/integer-to-roman/)
 * @author Finalcheat
 * @date 2016-04-09
 */

/**
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

/**
 * 首先参考[罗马数字](https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97)的定义。使用贪心算法的思想，循环中始终找出能表示该数字的最大罗马数字，拼接起来然后减去该数字。
 */

class Solution {
    public:
        string intToRoman(int num) {
            string index[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 
            int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            const int length = sizeof(value) / sizeof(int);
            string result;
            int i = 0;
            while (num && i < length) {
                while (num >= value[i]) {
                    result += index[i];
                    num -= value[i];
                }
                ++i;
            }
            return result;
        }
};
