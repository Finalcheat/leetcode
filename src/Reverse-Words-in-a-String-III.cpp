/**
 * @file Reverse-Words-in-a-String-III.cpp
 * @brief 反转字符串III(https://leetcode.com/problems/reverse-words-in-a-string-iii/description/)
 * @author Finalcheat
 * @date 2018-01-07
 */

/**
 * Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 * Example 1:
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 */

/**
 * 碰到空格字符分割字符串即可，注意极端情况。
 */


class Solution {

    public:
        string reverseWords(string s) {
            int index = -1;
            for (size_t i = 0; i < s.size(); ++i) {
                if (s[i] == ' ') {
                    if (i > 0 && s[i - 1] != ' ') {
                        reverseWords(s, index + 1, i - 1);
                    }
                    index = i;
                }
            }
            reverseWords(s, index + 1, s.size() - 1);
            return s;
        }

    private:
        void reverseWords(string& s, int start, int end) {
            while (start < end) {
                int tmp = s[start];
                s[start] = s[end];
                s[end] = tmp;
                ++start;
                --end;
            }
    }
};
