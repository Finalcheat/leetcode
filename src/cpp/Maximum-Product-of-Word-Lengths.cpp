/**
 * @file Maximum-Product-of-Word-Lengths.cpp
 * @brief 单词长度的最大积(https://leetcode.com/problems/maximum-product-of-word-lengths/)
 * @author Finalcheat
 * @date 2016-03-13
 */

/**
 * Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
 * Example 1:
 * Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 * Return 16
 * The two words can be "abcw", "xtfn".
 * Example 2:
 * Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 * Return 4
 * The two words can be "ab", "cd".
 * Example 3:
 * Given ["a", "aa", "aaa", "aaaa"]
 * Return 0
 * No such pair of words.
 */

/**
 * 用一个int的26位来保存字母的信息，不关心字母出现的次数，只关心是否出现，然后循环遍历单词比较即可。
 */

class Solution {
    public:
        int maxProduct(vector<string>& words) {
            vector<int> bitArray(words.size());
            for (size_t i = 0; i < words.size(); ++i) {
                bitArray[i] = 0;
                for (size_t j = 0; j < words[i].size(); ++j) {
                    bitArray[i] |= (1 << (words[i][j] - 'a'));
                }
            }
            int maxProduct = 0;
            for (size_t i = 0; i < words.size(); ++i) {
                for (size_t j = i + 1; j < words.size(); ++j) {
                    if (((bitArray[i] & bitArray[j]) == 0) && words[i].size() * words[j].size() > maxProduct) {
                        maxProduct = words[i].size() * words[j].size();
                    }
                }
            }
            return maxProduct;
        }
};
