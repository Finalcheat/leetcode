/**
 * @file Reverse-Vowels-of-a-String.cpp
 * @brief 反转字符串中的元音字符(https://leetcode.com/problems/reverse-vowels-of-a-string/) 
 * @author Finalcheat
 * @date 2016-05-07
 */

/**
 * Write a function that takes a string as input and reverse only the vowels of a string.
 * Example 1:
 * Given s = "hello", return "holle".
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 */

/**
 * 遍历字符串，用两个指针找出未反转的元音字符然后交换。
 */

class Solution {
    public:
        string reverseVowels(string s) {
            int start = 0;
            int end = s.size() - 1;
            std::set<char> vowelsSet;
            vowelsSet.insert('a');
            vowelsSet.insert('A');
            vowelsSet.insert('e');
            vowelsSet.insert('E');
            vowelsSet.insert('i');
            vowelsSet.insert('I');
            vowelsSet.insert('o');
            vowelsSet.insert('O');
            vowelsSet.insert('u');
            vowelsSet.insert('U');
            while (true) {
                while (start < end && vowelsSet.find(s[start]) == vowelsSet.end()) {
                    ++start;
                }
                while (start < end && vowelsSet.find(s[end]) == vowelsSet.end()) {
                    --end;
                }
                if (start >= end) {
                    break;
                }
                char c = s[start];
                s[start] = s[end];
                s[end] = c;
                ++start;
                --end;
            }
            return s;
        }
};
