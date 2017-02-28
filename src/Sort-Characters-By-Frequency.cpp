/**
 * @file Sort-Characters-By-Frequency.cpp
 * @brief 按照字符出现的频次排序字符串(https://leetcode.com/problems/sort-characters-by-frequency)
 * @author Finalcheat
 * @date 2017-02-28
 */

/**
 * Given a string, sort it in decreasing order based on the frequency of characters.
 * Example 1:
 * Input:
 * "tree"
 * Output:
 * "eert"
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 * Example 2:
 * Input:
 * "cccaaa"
 * Output:
 * "cccaaa"
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * Example 3:
 * Input:
 * "Aabb"
 * Output:
 * "bbAa"
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 */

/**
 * 首先用hashtable记录每个字符出现的次数为kvMap，接着反转key-value(vkMap)，也就是出现次数作为key，字符作为value，注意此时key也就是出现次数可能重复所以需要使用multimap，同时把所有字符的出现次数添加到vector中，
 * 然后把vector降序，最后遍历vector同时在vkMap中查找相应的字符。
 */

class Solution {
    public:
        string frequencySort(string s) {
            std::unordered_map<char, size_t> kvMap;
            std::unordered_multimap<size_t, char> vkMap;
            for (size_t i = 0; i < s.size(); ++i) {
                ++kvMap[s[i]];
            }
            std::vector<size_t> counts;
            typedef typename std::unordered_multimap<size_t, char>::value_type Value_type;
            for (std::unordered_map<char, size_t>::const_iterator it = kvMap.begin(); it != kvMap.end(); ++it) {
                vkMap.insert(Value_type(it->second, it->first));
                counts.push_back(it->second);
            }
            std::sort(counts.begin(), counts.end(), std::greater<size_t>());
            string result;
            for (size_t i = 0; i < counts.size(); ++i) {
                const size_t count = counts[i];
                std::unordered_multimap<size_t, char>::const_iterator it = vkMap.find(count);
                if (it != vkMap.end()) {
                    result += std::string(it->first, it->second);
                    vkMap.erase(it);
                }
            }
            return result;
        }
};
