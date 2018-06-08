/**
 * @file Implement-strStr.cpp
 * @brief 实现strStr(https://leetcode.com/problems/implement-strstr/)
 * @author Finalcheat
 * @date 2017-04-13
 */

/**
 * Implement strStr().
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

/**
 * 两个指针遍历对比即可，更高大上的解法可以用KMP算法。
 */

class Solution {
    public:
        int strStr(string haystack, string needle) {
            if (haystack.empty() && needle.empty()) {
                return 0;
            }
            int len = haystack.size() - needle.size();
            for (int i = 0; i <= len; ++i) {
                bool find = true;
                for (size_t j = 0; j < needle.size(); ++j) {
                    if (i + j > haystack.size() || haystack[i + j] != needle[j]) {
                        find = false;
                        break;
                    }
                }
                if (find) {
                    return i;
                }
            }
            return -1;
        }
};
