/**
 * @file Generate-a-String-With-Characters-That-Have-Odd-Counts.cpp
 * @brief 生成含有奇数字符的字符串(https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/)
 * @author Finalcheat
 * @date 2020-04-14
 */

/**
 * Given an integer n, return a string with n characters such that each character in such string occurs an odd number of times.
 * The returned string must contain only lowercase English letters. If there are multiples valid strings, return any of them.
 * Example 1:
 * Input: n = 4
 * Output: "pppz"
 * Explanation: "pppz" is a valid string since the character 'p' occurs three times and the character 'z'
 * occurs once. Note that there are many other valid strings such as "ohhh" and "love".
 * Example 2:
 * Input: n = 2
 * Output: "xy"
 * Explanation: "xy" is a valid string since the characters 'x' and 'y' occur once. Note that there are many
 * other valid strings such as "ag" and "ur".
 * Example 3:
 * Input: n = 7
 * Output: "holasss"
 */

/**
 * n是奇数时，返回n个'a'，n是偶数时，将最后一个字符改成'b'。
 */

class Solution {
    public:
        string generateTheString(int n) {
            string result(n, 'a');
            if (n > 0 && n % 2 == 0) {
                result[n - 1] = 'b';
            }
            return result;
        }
};
