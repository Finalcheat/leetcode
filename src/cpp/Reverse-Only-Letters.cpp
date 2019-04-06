/**
 * @file Reverse-Only-Letters.cpp
 * @brief 字符串中仅字母反转(https://leetcode.com/problems/reverse-only-letters/description/)
 * @author Finalcheat
 * @date 2018-11-02
 */

/**
 * Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.
 * Example 1:
 * Input: "ab-cd"
 * Output: "dc-ba"
 * Example 2:
 * Input: "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * Example 3:
 * Input: "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 */

/**
 * 反转算法就是前后双指针遍历交换，按题中要求判断好是否是字母即可。
 */


class Solution {
    public:
        string reverseOnlyLetters(string S) {
            int first = 0;
            int last = S.size() - 1;
            while (first < last) {
                while (first < last && !isLetter(S[first])) {
                    ++first;
                }
                while (first < last && !isLetter(S[last])) {
                    --last;
                }
                if (first < last) {
                    std::swap(S[first], S[last]);
                    ++first;
                    --last;
                }
            }
            return S;
        }
    private:
        bool isLetter(const char c) {
            if (c >= 'a' && c <= 'z') {
                return true;
            } else if (c >= 'A' && c <= 'Z') {
                return true;
            }
            return false;
        }
};
