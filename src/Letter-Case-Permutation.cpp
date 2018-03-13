/**
 * @file Letter-Case-Permutation.cpp
 * @brief 字母大小写排列(https://leetcode.com/problems/letter-case-permutation/description/)
 * @author Finalcheat
 * @date 2018-03-13
 */

/**
 * Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.
 * Examples:
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * Input: S = "3z4"
 * Output: ["3z4", "3Z4"]
 * Input: S = "12345"
 * Output: ["12345"]
 */

/**
 * 这是一道排列组合问题，首先找到所有的字母，然后进行排列，排列的方法可以用bit进行判断改变大小写。
 */


class Solution {
    public:
        vector<string> letterCasePermutation(string S) {
            vector<size_t> letterPos;
            for (size_t i = 0; i < S.size(); ++i) {
                const char c = S[i];
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    letterPos.push_back(i);
                }
            }
            vector<string> result;
            int count = std::pow(2, letterPos.size());
            while (--count >= 0) {
                string tmp = S;
                int tmpCount = count;
                size_t tmpIndex = 0;
                while (tmpCount > 0) {
                    if ((tmpCount & 1)) {
                        const char c = S[letterPos[tmpIndex]];
                        if (c >= 'a' && c <= 'z') {
                            tmp[letterPos[tmpIndex]] = c - 'a' + 'A';
                        } else {
                            tmp[letterPos[tmpIndex]] = c - 'A' + 'a';
                        }
                    }
                    ++tmpIndex;
                    tmpCount = tmpCount >> 1;
                }
                result.push_back(tmp);
            }
            return result;
        }
};
