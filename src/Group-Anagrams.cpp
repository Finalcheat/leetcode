/**
 * @file Group-Anagrams.cpp
 * @brief 变形词(https://leetcode.com/problems/anagrams/) 
 * @author Finalcheat
 * @date 2016-06-19
 */

/**
 * Given an array of strings, group anagrams together.
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note: All inputs will be in lower-case.
 */

/**
 * 将每个词内部按字母表排序，相同的变形词排序后将得到同一个key，用哈希表将相同的key聚合起来。
 */

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            std::unordered_map<std::string, std::vector<std::string>> u;
            for (size_t i = 0; i < strs.size(); ++i) {
                std::string s = strs[i];
                std::sort(s.begin(), s.end());
                auto it = u.find(s);
                if (it != u.end()) {
                    std::vector<std::string>& v = it->second;
                    v.push_back(strs[i]);
                } else {
                    std::vector<std::string> v{strs[i]};
                    u[s] = v;
                }
            }
            std::vector<std::vector<std::string>> result;
            for (auto it = u.begin(); it != u.end(); ++it) {
                result.push_back(it->second);
            }
            return result;
        }
};
