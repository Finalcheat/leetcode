/**
 * @file Letter-Combinations-of-a-Phone-Number.cpp
 * @brief 电话号码的字母组合(https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/)
 * @author Finalcheat
 * @date 2018-10-02
 */

/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

/**
 * dfs搜索即可，注意""的情况。
 */


class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> result;
            std::unordered_map<char, vector<char> > u;
            u['2'] = vector<char>{'a', 'b', 'c'};
            u['3'] = vector<char>{'d', 'e', 'f'};
            u['4'] = vector<char>{'g', 'h', 'i'};
            u['5'] = vector<char>{'j', 'k', 'l'};
            u['6'] = vector<char>{'m', 'n', 'o'};
            u['7'] = vector<char>{'p', 'q', 'r', 's'};
            u['8'] = vector<char>{'t', 'u', 'v'};
            u['9'] = vector<char>{'w', 'x', 'y', 'z'};
            string cur;
            dfs(u, digits, 0, result, cur);
            return result;
        }
    private:
        void dfs(const std::unordered_map<char, vector<char> >& u, const string& digits, size_t idx,
                vector<string>& result, string& cur) {
            if (idx >= digits.size()) {
                if (!cur.empty()) {
                    result.push_back(cur);
                }
                return;
            }
            const char c = digits[idx];
            const auto iter = u.find(c);
            if (iter == u.end()) {
                return;
            }
            const vector<char>& v = iter->second;
            ++idx;
            for (const char cc : v) {
                cur.push_back(cc);
                dfs(u, digits, idx, result, cur);
                cur.pop_back();
            }
        }
};
