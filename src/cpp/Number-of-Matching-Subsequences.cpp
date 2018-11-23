/**
 * @file Number-of-Matching-Subsequences.cpp
 * @brief 匹配子序列的单词数(https://leetcode.com/problems/number-of-matching-subsequences/description/)
 * @author Finalcheat
 * @date 2018-09-30
 */

/**
 * Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
 * Example :
 * Input:
 * S = "abcde"
 * words = ["a", "bb", "acd", "ace"]
 * Output: 3
 * Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
 */

/**
 * hashtable记录S元素与坐标的对应关系，遍历words过程中在hashtable中寻找word的字符。
 */


class Solution {
    public:
        int numMatchingSubseq(string S, vector<string>& words) {
            std::unordered_map<char, vector<int> > u;
            for (int i = 0; i < S.size(); ++i) {
                const char c = S[i];
                auto iter = u.find(c);
                if (iter == u.end()) {
                    vector<int> idxs{i};
                    u[c] = idxs;
                } else {
                    vector<int>& idxs = iter->second;
                    idxs.push_back(i);
                }
            }
            int count = 0;
            for (const string& word : words) {
                bool isSubsequences = true;
                int prev = -1;
                for (int i = 0; i < word.size(); ++i) {
                    const auto iter = u.find(word[i]);
                    if (iter == u.end()) {
                        isSubsequences = false;
                        break;
                    }
                    const vector<int>& idxs = iter->second;
                    const auto findIter = std::upper_bound(idxs.begin(), idxs.end(), prev);
                    if (findIter == idxs.end()) {
                        isSubsequences = false;
                        break;
                    }
                    prev = *findIter;
                }
                if (isSubsequences) {
                    ++count;
                }
            }
            return count;
        }
};
