/**
 * @file Find-Words-That-Can-Be-Formed-by-Characters.cpp
 * @brief 找出由字符构成的单词(https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/)
 * @author Finalcheat
 * @date 2019-09-17
 */

/**
 * You are given an array of strings words and a string chars.
 * A string is good if it can be formed by characters from chars (each character can only be used once).
 * Return the sum of lengths of all good strings in words.
 * Example 1:
 * Input: words = ["cat","bt","hat","tree"], chars = "atach"
 * Output: 6
 * Explanation:
 * The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
 * Example 2:
 * Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
 * Output: 10
 * Explanation:
 * The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 */

/**
 * 用hashtable作为辅助结构记录字符出现次数，遍历比较即可。
 */

class Solution {
    public:
        int countCharacters(vector<string>& words, string chars) {
            std::unordered_map<char, int> u;
            for (const char c : chars) {
                ++u[c];
            }
            
            int sum = 0;
            for (const string& word : words) {
                std::unordered_map<char, int> uCopy(u);
                bool b = true;
                for (const char c : word) {
                    if (--uCopy[c] < 0) {
                        b = false;
                        break;
                    }
                }
                if (b) {
                    sum += word.size();
                }
            }
            
            return sum;
        }
};
