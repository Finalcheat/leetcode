/**
 * @file Longest-Word-in-Dictionary-through-Deleting.cpp
 * @brief 删除字符后得到字典中的最长单词(https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)
 * @author Finalcheat
 * @date 2017-03-16
 */

/**
 * Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given 
 * string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible 
 * result, return the empty string.
 * Example 1:
 * Input:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * Output: 
 * "apple"
 * Example 2:
 * Input:
 * s = "abpcplea", d = ["a","b","c"]
 * Output: 
 * "a"
 */

/**
 * 记录每个字符索引位置，遍历字典单词的时候查找字符的索引位置，只要每个字符的索引位置都比前一个字符的索引位置大就是所求了，最后比较谁最长就行了。
 */

class Solution {
    public:
        string findLongestWord(string s, vector<string>& d) {
            vector<vector<int>> v(26);
            for (size_t i = 0; i < s.size(); ++i) {
                vector<int>& indexs = v[s[i] - 'a'];
                indexs.push_back(i);
            }
            for (size_t i = 0; i < v.size(); ++i) {
                vector<int>& indexs = v[i];
                std::sort(indexs.begin(), indexs.end());
            }
            
            string result;
            for (size_t i = 0; i < d.size(); ++i) {
                const string& s = d[i];
                if (s.size() < result.size()) {
                    continue;
                }
                int prev = -1;
                bool find = true;
                for (size_t j = 0; j < s.size(); ++j) {
                    vector<int> indexs = v[s[j] - 'a'];
                    auto lower = std::lower_bound(indexs.begin(), indexs.end(), prev);
                    if (lower == indexs.end()) {
                        find = false;
                        break;
                    }
                    if (*lower == prev) {
                        ++lower;
                    
                        if (lower == indexs.end()) {
                            find = false;
                            break;
                        }
                    }
                    prev = *lower;
                }
                if (find) {
                    if (s.size() > result.size()) {
                        result = s;
                    } else if (s < result) {
                        result = s;
                    }
                }
            }
            return result;
        }
};
