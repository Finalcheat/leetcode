/**
 * @file Longest-Word-in-Dictionary.cpp
 * @brief 字典的最长词(https://leetcode.com/problems/longest-word-in-dictionary/description/)
 * @author Finalcheat
 * @date 2018-01-11
 */

/**
 * Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.
 * If there is no answer, return the empty string.
 * Example 1:
 * Input:
 * words = ["w","wo","wor","worl", "world"]
 * Output: "world"
 * Explanation:
 * The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
 * Example 2:
 * Input:
 * words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * Output: "apple"
 * Explanation:
 * Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
 */

/**
 * 先排序使得前缀的词聚在一起，然后遍历过程中使用hash table作为辅助判断前缀。
 */


class Solution {
    public:
        string longestWord(vector<string>& words) {
            std::sort(words.begin(), words.end());
            std::unordered_set<string> u;
            string result;
            for (size_t i = 0; i < words.size(); ++i) {
                const string& word = words[i];
                const string preWord = word.substr(0, word.size() - 1);
                if (preWord.empty() || u.find(preWord) != u.end()) {
                    u.insert(word);
                    if (word.size() > result.size()) {
                        result = word;
                    }
                }
            }
            return result;
        }
};
