/**
 * @file To-Lower-Case.cpp
 * @brief 转换为小写(https://leetcode.com/problems/to-lower-case/description/)
 * @author Finalcheat
 * @date 2018-07-21
 */

/**
 * Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
 * Example 1:
 * Input: "Hello"
 * Output: "hello"
 * Example 2:
 * Input: "here"
 * Output: "here"
 * Example 3:
 * Input: "LOVELY"
 * Output: "lovely"
 */

/**
 * 遍历每个字符，如果是大写的话转换为小写即可。
 */


class Solution {
    public:
        string toLowerCase(string str) {
            for (size_t i = 0; i < str.size(); ++i) {
                const char c = str[i];
                if (c >= 'A' && c <= 'Z') {
                    str[i] = c - 'A' + 'a';
                }
            }
            return str;
        }
};
