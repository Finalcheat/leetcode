/**
 * @file Shuffle-String.cpp
 * @brief 重新排列字符串(https://leetcode.com/problems/shuffle-string/description/)
 * @author Finalcheat
 * @date 2024-04-20
 */


/**
 * 遍历写入字符就好
 */


class Solution {
    public:
        string restoreString(string s, vector<int>& indices) {
            assert(s.size() == indices.size());
            string res(s.size(), '\0');
            for (size_t i = 0; i < indices.size(); ++i) {
                res[indices[i]] = s[i];
            }
            return res;
        }
};
