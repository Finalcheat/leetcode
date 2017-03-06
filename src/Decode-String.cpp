/**
 * @file Decode-String.cpp
 * @brief 字符串解码(https://leetcode.com/problems/decode-string)
 * @author Finalcheat
 * @date 2017-03-06
 */

/**
 * Given an encoded string, return it's decoded string.
 * The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
 * You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
 * Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
 * Examples:
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

/**
 * 字符解析有三种情况：数字、字母、右中括号(左中括号可以暂时不考虑因为题目要求输入是正确的，所以必在数字后面)，在遍历过程中定义1个字符串存储当前解析到的内容，
 * 遇到数字字符则解析对应的数字同时跳过后面的左中括号，然后递归调用自己得到对应的字符串；
 * 遇到字母就添加上去；
 * 遇到右中括号则结束循环;
 */

class Solution {
    public:
        string decodeString(string s) {
            string::const_iterator start = s.begin();
            string::const_iterator end = s.end();
            string result = decodeString(start, end);
            return result;
        }
        
        string decodeString(string::const_iterator& it, string::const_iterator end) {
            string result;
            while (it != end && *it != ']') {
                if (*it >= '0' && *it <= '9') {
                    int count = 0;
                    while (*it >= '0' && *it <= '9') {
                        count = count * 10 + *it - '0';
                        ++it;
                    }
                    ++it;
                    string s = decodeString(it, end);
                    ++it;
                    for (int i = 0; i < count; ++i) {
                        result += s;
                    }
                } else {
                    result += *it;
                    ++it;
                }
            }
            return result;
        }
};
