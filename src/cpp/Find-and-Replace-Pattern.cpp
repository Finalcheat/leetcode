/**
 * @file Find-and-Replace-Pattern.cpp
 * @brief 查找和替换模式(https://leetcode.com/problems/find-and-replace-pattern/description/)
 * @author Finalcheat
 * @date 2018-09-16
 */

/**
 * You have a list of words and a pattern, and you want to know which words in words matches the pattern.
 * A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
 * (Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
 * Return a list of the words in words that match the given pattern.
 * You may return the answer in any order.
 * Example 1:
 * Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 * Output: ["mee","aqq"]
 * Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
 * "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
 * since a and b map to the same letter.
 */

/**
 * 用hashtable记录字符出现的下标位置，遍历一遍即可找出匹配模式。
 */


class Solution {
    public:
        vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
            vector<string> result;
            for (const string& word : words) {
                if (word.size() != pattern.size()) {
                    continue;
                }
                std::unordered_map<char, int> u;
                std::unordered_map<char, int> uu;
                bool match = true;
                for (int i = 0; i < word.size(); ++i) {
                    if (u[word[i]] != uu[pattern[i]]) {
                        match = false;
                        break;
                    }
                    u[word[i]] = i + 1;
                    uu[pattern[i]] = i + 1;
                }
                if (match) {
                    result.push_back(word);
                }
            }
            return result;
        }
};
