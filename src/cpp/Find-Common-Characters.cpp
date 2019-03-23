/**
 * @file Find-Common-Characters.cpp
 * @brief 寻找共同的字符(https://leetcode.com/problems/find-common-characters/)
 * @author Finalcheat
 * @date 2019-03-12
 */

/**
 * Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.
 * You may return the answer in any order.
 * Example 1:
 * Input: ["bella","label","roller"]
 * Output: ["e","l","l"]
 * Example 2:
 * Input: ["cool","lock","cook"]
 * Output: ["c","o"]
 */

/**
 * 遍历两两取交集即可。
 */


class Solution {
    public:
        vector<string> commonChars(vector<string>& A) {
            vector<string> result;
            if (A.empty()) {
                return result;
            }
            vector<char> lastVt(26, 0);
            for (size_t i = 0; i < A[0].size(); ++i) {
                const char c = A[0][i];
                assert(c >= 'a' && c <= 'z');
                ++lastVt[c - 'a'];
            }
            for (size_t i = 1; i < A.size(); ++i) {
                vector<char> tmpVt(26, 0);
                const string& str = A[i];
                for (size_t j = 0; j < str.size(); ++j) {
                    const char c = str[j];
                    assert(c >= 'a' && c <= 'z');
                    const size_t idx = c - 'a';
                    if (tmpVt[idx] < lastVt[idx]) {
                        ++tmpVt[idx];
                    }
                }
                lastVt.swap(tmpVt);
            }
            for (size_t i = 0; i < lastVt.size(); ++i) {
                const int num = lastVt[i];
                if (num == 0) {
                    continue;
                }
                for (int j = 0; j < num; ++j) {
                    result.push_back(string(1, i + 'a'));
                }
            }
            return result;
        }
};
