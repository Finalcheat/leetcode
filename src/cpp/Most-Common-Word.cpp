/**
 * @file Most-Common-Word.cpp
 * @brief 最常见的单词(https://leetcode.com/problems/most-common-word/description/)
 * @author Finalcheat
 * @date 2018-08-17
 */

/**
 * Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.
 * Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.
 * Example:
 * Input:
 * paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
 * banned = ["hit"]
 * Output: "ball"
 * Explanation:
 * "hit" occurs 3 times, but it is a banned word.
 * "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
 * Note that words in the paragraph are not case sensitive,
 * that punctuation is ignored (even if adjacent to words, such as "ball,"),
 * and that "hit" isn't the answer even though it occurs more because it is banned.
 */

/**
 * 分割单词统计就好了，可是stl里面没有split，只能自己遍历分割处理细节。
 */


class Solution {
    public:
        string mostCommonWord(string paragraph, vector<string>& banned) {
            std::unordered_set<string> u;
            for (const string& s : banned) {
                u.insert(s);
            }
            size_t pos = 0;
            while (pos < paragraph.size() && !isLetter(paragraph[pos])) {
                ++pos;
            }
            size_t prev = pos;
            std::unordered_map<string, size_t> uu;
            size_t maximum = 0;
            string result;
            paragraph += " ";
            for (; pos < paragraph.size(); ++pos) {
                if (isLetter(paragraph[prev]) && !isLetter(paragraph[pos])) {
                    string s = paragraph.substr(prev, pos - prev);
                    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
                    auto iter = u.find(s);
                    if (iter == u.end()) {
                        size_t count = ++uu[s];
                        if (count > maximum) {
                            maximum = count;
                            result = s;
                        }
                    }
                    prev = pos;
                } else {
                    if (!isLetter(paragraph[prev])) {
                        prev = pos;
                    }
                }
            }
            return result;
        }
    private:
        bool isLetter(const char c) {
            if (c >= 'a' && c <= 'z') {
                return true;
            } else if (c >= 'A' && c <= 'Z') {
                return true;
            }
            return false;
        }
};
