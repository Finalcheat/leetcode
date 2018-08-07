/**
 * @file Short-Encoding-of-Words.cpp
 * @brief 短编码的单词(https://leetcode.com/problems/short-encoding-of-words/description/)
 * @author Finalcheat
 * @date 2018-07-24
 */

/**
 * Given a list of words, we may encode it by writing a reference string S and a list of indexes A.
 * For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].
 * Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.
 * What is the length of the shortest reference string S possible that encodes the given words?
 * Example:
 * Input: words = ["time", "me", "bell"]
 * Output: 10
 * Explanation: S = "time#bell#" and indexes = [0, 2, 5].
 */

/**
 * 思路就是找相同后缀，可以反转字符串，然后排序有着相同后缀的字符串则会连在一起。
 */


class Solution {
    public:
        int minimumLengthEncoding(vector<string>& words) {
            if (words.empty()) {
                return 0;
            }
            vector<string> reverseWords(words.size() + 1);
            for (size_t i = 0; i < words.size(); ++i) {
                const std::string& word = words[i];
                reverseWords[i] = std::string(word.rbegin(), word.rend());
            }
            std::sort(reverseWords.begin(), reverseWords.end() - 1);
            reverseWords[words.size()] = "";
            int result = 0;
            for (size_t i = 1; i < reverseWords.size(); ++i) {
                const std::string& word = reverseWords[i];
                const std::string& lastWord = reverseWords[i - 1];
                if (word.find(lastWord) != 0) {
                    result += (lastWord.size() + 1);
                }
            }
            return result;
        }
};
