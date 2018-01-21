/**
 * @file License-Key-Formatting.cpp
 * @brief 序列号格式(https://leetcode.com/problems/license-key-formatting/description/)
 * @author Finalcheat
 * @date 2018-01-21
 */

/**
 * You are given a license key represented as a string S which consists only alphanumeric character and dashes. The string is separated into N+1 groups by N dashes.
 * Given a number K, we would want to reformat the strings such that each group contains exactly K characters, except for the first group which could be shorter than K, but still must contain at least one character. Furthermore, there must be a dash inserted between two groups and all lowercase letters should be converted to uppercase.
 * Given a non-empty string S and a number K, format the string according to the rules described above.
 * Example 1:
 * Input: S = "5F3Z-2e-9-w", K = 4
 * Output: "5F3Z-2E9W"
 * Explanation: The string S has been split into two parts, each part has 4 characters.
 Note that the two extra dashes are not needed and can be removed.
 * Example 2:
 * Input: S = "2-5g-3-J", K = 2
 * Output: "2-5G-3J"
 * Explanation: The string S has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
 */

/**
 * 首先统计'-'字符的数量，然后计算出最终结果'-'的数量和处理首段字符，最后遍历每k个字符插入'-'即可。
 */


class Solution {

    public:
        string licenseKeyFormatting(string S, int K) {
            int dashCount = 0;
            for (size_t i = 0; i < S.size(); ++i) {
                if (S[i] == '-') {
                    ++dashCount;
                }
            }
            string result;
            size_t firstCount = (S.size() - dashCount) % K;
            dashCount = (S.size() - dashCount) / K - 1 + (firstCount > 0 ? 1 : 0);
            string::const_iterator it = S.begin();
            while (firstCount > 0 && it != S.end()) {
                if (*it != '-') {
                    result.push_back(convertedToUppercase(*it));
                    --firstCount;
                }
                ++it;
                if (firstCount == 0 && dashCount > 0) {
                    result.push_back('-');
                    --dashCount;
                }
            }
            int k = 0;
            while (it != S.end()) {
                if (*it != '-') {
                    result.push_back(convertedToUppercase(*it));
                    ++k;
                    if (k % K == 0 && dashCount > 0) {
                        result.push_back('-');
                        --dashCount;
                    }
                }
                ++it;
            }
            return result;
        }

    private:
        char convertedToUppercase(char c) {
            if (c >= 'a' && c <= 'z') {
                return c - 'a' + 'A';
            }
            return c;
        }

};
