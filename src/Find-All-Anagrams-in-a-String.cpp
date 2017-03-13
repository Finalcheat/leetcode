/**
 * @file Find-All-Anagrams-in-a-String.cpp
 * @brief 找出字符串中所有的同位词(https://leetcode.com/problems/third-maximum-number/)
 * @author Finalcheat
 * @date 2017-03-13
 */

/**
 * Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 * Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 * The order of output does not matter.
 * Example 1:
 * Input:
 * s: "cbaebabacd" p: "abc"
 * Output:
 * [0, 6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * Example 2:
 * Input:
 * s: "abab" p: "ab"
 * Output:
 * [0, 1, 2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

/**
 * 同位词的特点是字符出现次数一致而不用管相对位置，所以考虑使用hashtable存储字符的出现次数然后对比即可，但要注意极端情况，比如整个字符串中所有字符都是同一个的这种情况。
 */

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            if (s.size() < p.size()) {
                return vector<int>();
            }
            std::unordered_map<char, int> u;
            for (size_t i = 0; i < p.size(); ++i) {
                ++u[p[i]];
            }
            vector<int> result;
            bool find = false;
            char lastChar;
            for (size_t i = 0; i < s.size(); ++i) {
                if (i + p.size() > s.size()) {
                    break;
                }
                const char c = s[i];
                if (find && lastChar == s[i + p.size() - 1]) {
                    result.push_back(i);
                    lastChar = c;
                    continue;
                }
                std::unordered_map<char, int>::const_iterator it = u.find(c);
                if (it != u.end()) {
                    std::unordered_map<char, int> tmp = u;
                    --tmp[c];
                    find = true;
                    for (size_t j = 1; j < p.size(); ++j) {
                        if (i + j >= s.size()) {
                            find = false;
                            break;
                        }
                        if (--tmp[s[i + j]] < 0) {
                            find = false;
                            break;
                        }
                    }
                    if (find) {
                        lastChar = c;
                        result.push_back(i);
                    }
                }
            }
            return result;
        }
};
