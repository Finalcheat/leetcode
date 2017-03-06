/**
 * @file Longest-Palindrome.cpp
 * @brief 最长的回文长度(https://leetcode.com/problems/longest-palindrome)
 * @author Finalcheat
 * @date 2017-03-06
 */

/**
 * Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * Example:
 * Input:
 * "abccccdd"
 * Output:
 * 7
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

/**
 * 用hashtable存储每个字符出现的次数，出现次数为偶数的必能构成回文，直接加到总数即可，对于出现次数为奇数的字符，将其-1变成偶数加到总数，
 * 最后随便拿奇数当中的一个字符(如果有)放到正中间构造最长的回文。
 */

class Solution {
    public:
        int longestPalindrome(string s) {
            std::unordered_map<char, int> u;
            for (size_t i = 0; i < s.size(); ++i) {
                ++u[s[i]];
            }
            int count = 0;
            int max = 0;
            for (std::unordered_map<char, int>::const_iterator it = u.begin(); it != u.end(); ++it) {
                if (it->second % 2 == 0) {
                    count += it->second;
                } else {
                    count += it->second - 1;
                    if (max < it->second) {
                        max = it->second;
                    }
                }
            }
            if (max != 0) {
                count += 1;
            }
            return count;
        }
};
