/**
 * @file Length-of-Last-Word.cpp
 * @brief 最后单词的长度(https://leetcode.com/problems/length-of-last-word/)
 * @author Finalcheat
 * @date 2016-03-19
 */

/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

/**
 * 求最后一个单词的长度，用两个指针从字符串尾部开始遍历，找到单词的开始和结束位置，相减即可得到字符串长度。
 */

class Solution {
    public:
        int lengthOfLastWord(string s) {
            string::const_reverse_iterator wordEnd = s.crbegin();
            while (wordEnd != s.crend() && *wordEnd == ' ') {
                ++wordEnd;
            }
            string::const_reverse_iterator wordBegin = wordEnd;
            while (wordBegin != s.crend() && *wordBegin != ' ') {
                ++wordBegin;
            }
            
            int len = wordBegin - wordEnd;
            return len;
        }
};
