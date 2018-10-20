/**
 * @file Uncommon-Words-from-Two-Sentences.cpp
 * @brief 两句话中的不寻常单词(https://leetcode.com/problems/uncommon-words-from-two-sentences/description/)
 * @author Finalcheat
 * @date 2018-10-19
 */

/**
 * We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)
 * A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
 * Return a list of all uncommon words.
 * You may return the list in any order.
 * Example 1:
 * Input: A = "this apple is sweet", B = "this apple is sour"
 * Output: ["sweet","sour"]
 * Example 2:
 * Input: A = "apple apple", B = "banana"
 * Output: ["banana"]
 */

/**
 * 分割然后用hashmap存储单词出现次数，最后按规则对比即可。
 */


class Solution {
    public:
        vector<string> uncommonFromSentences(string A, string B) {
            std::unordered_map<string, int> aHashMap;
            std::unordered_map<string, int> bHashMap;
            vector<string> aWords = split(A, ' ');
            for (const string& word : aWords) {
                ++aHashMap[word];
            }
            vector<string> bWords = split(B, ' ');
            for (const string& word : bWords) {
                ++bHashMap[word];
            }
            vector<string> result;
            for (const string& word : aWords) {
                const int aCount = aHashMap[word];
                if (aCount > 1) {
                    continue;
                }
                const auto bIter = bHashMap.find(word);
                if (bIter == bHashMap.end()) {
                    result.push_back(word);
                }
            }
            for (const string& word : bWords) {
                const int bCount = bHashMap[word];
                if (bCount > 1) {
                    continue;
                }
                const auto aIter = aHashMap.find(word);
                if (aIter == aHashMap.end()) {
                    result.push_back(word);
                }
            }
            return result;
        }
    private:
        std::vector<std::string> split(const std::string &s, char delim) {
            std::stringstream ss(s);
            std::string item;
            std::vector<std::string> elems;
            while (std::getline(ss, item, delim)) {
                elems.push_back(std::move(item));
            }
            return elems;
        }
};
