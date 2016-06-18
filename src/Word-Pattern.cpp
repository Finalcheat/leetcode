/**
 * @file Word-Pattern.cpp
 * @brief 字符串模式匹配(https://leetcode.com/problems/word-pattern/)
 * @author Finalcheat
 * @date 2016-06-18
 */

/**
 * Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 * Examples:
 * * pattern = "abba", str = "dog cat cat dog" should return true.
 * * pattern = "abba", str = "dog cat cat fish" should return false.
 * * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
 */

/**
 * 遍历过程中用哈希表存储字符和字符串的上一次出现位置，发现不匹配的直接返回false，很多细节需要注意，最后还需要比较按空格分割后的字符串个数与模式字符串长度是否相等。
 */

class Solution {
    public:
        bool wordPattern(string pattern, string str) {
            std::unordered_map<char, size_t> u1;
            std::unordered_map<std::string, size_t> u2;
            size_t pattern_index = 0;
            std::stringstream ss(str);
            std::string s;
            size_t str_count = 0;
            while (getline(ss, s, ' ')) {
                const char c = pattern[pattern_index];
                auto it1 = u1.find(c);
                auto it2 = u2.find(s);
                if ((it1 != u1.end() && it2 != u2.end() && it1->second != it2->second)) {
                    return false;
                } else if ((it1 == u1.end() && it2 != u2.end()) || (it1 != u1.end() && it2 == u2.end())) {
                    return false;
                }
                u1[c] = pattern_index;
                u2[s] = pattern_index;
                ++pattern_index;
                ++str_count;
            }
            return pattern.size() == str_count;
        }
};
