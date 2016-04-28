/**
 * @file Reverse-String.cpp
 * @brief 反转字符串(https://leetcode.com/problems/reverse-string/) 
 * @author Finalcheat
 * @date 2016-04-28
 */

/**
 * Write a function that takes a string as input and returns the string reversed.
 * Example:
 * Given s = "hello", return "olleh".
 */

/**
 * 很简单的循环，遍历字符串的一半交换即可。
 */

class Solution {
    public:
        string reverseString(string s) {
            const size_t len = s.size();
            for (size_t i = 0; i < len / 2; ++i) {
                std::swap(s[i], s[len - i - 1]);
            }
            return s;
        }
};
