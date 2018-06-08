/**
 * @file Shortest-Completing-Word.cpp
 * @brief 最短完整单词(https://leetcode.com/problems/shortest-completing-word/description/)
 * @author Finalcheat
 * @date 2018-03-20
 */

/**
 * Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate
 * Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.
 * It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.
 * The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.
 * Example 1:
 * Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
 * Output: "steps"
 * Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
 * Note that the answer is not "step", because the letter "s" must occur in the word twice.
 * Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
 * Example 2:
 * Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
 * Output: "pest"
 * Explanation: There are 3 smallest length words that contains the letters "s".
 * We return the one that occurred first.
 * Note:
 * 1. licensePlate will be a string with length in range [1, 7].
 * 2. licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
 * 3. words will have a length in the range [10, 1000].
 * 4. Every words[i] will consist of lowercase letters, and have length in range [1, 15].
 */

/**
 * 用hashtable记录字符的出现次数，然后遍历word过程中找到字符减1，最后判断word的长度即可。
 */


class Solution {
    public:
        string shortestCompletingWord(string licensePlate, vector<string>& words) {
            std::map<char, size_t> m;
            for (size_t i = 0; i < licensePlate.size(); ++i) {
                const char lc = licensePlate[i];
                if (lc >= 'a' && lc <= 'z') {
                    ++m[lc];
                } else if (lc >= 'A' && lc <= 'Z') {
                    ++m[lc - 'A' + 'a'];
                }
            }
            std::string result;
            for (size_t i = 0; i < words.size(); ++i) {
                const string& s = words[i];
                std::map<char, size_t> tmp = m;
                for (size_t j = 0; j < s.size(); ++j) {
                    const char c = s[j];
                    auto iter = tmp.find(c);
                    if (iter != tmp.end()) {
                        --(iter->second);
                        if (iter->second == 0) {
                            tmp.erase(iter);
                        }
                    }
                }
                if (tmp.empty() && (result.empty() || s.size() < result.size())) {
                    result = s;
                }
            }
            return result;
        }
};
