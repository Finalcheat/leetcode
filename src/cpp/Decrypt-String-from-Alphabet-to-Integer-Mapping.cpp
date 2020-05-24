/**
 * @file Decrypt-String-from-Alphabet-to-Integer-Mapping.cpp
 * @brief 从字母到整数的映射解密字符串(https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/)
 * @author Finalcheat
 * @date 2020-05-24
 */

/**
 * Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:
 * * Characters ('a' to 'i') are represented by ('1' to '9') respectively.
 * * Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
 * Return the string formed after mapping.
 * It's guaranteed that a unique mapping will always exist.
 * Example 1:
 * Input: s = "10#11#12"
 * Output: "jkab"
 * Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
 * Example 2:
 * Input: s = "1326#"
 * Output: "acz"
 * Example 3:
 * Input: s = "25#"
 * Output: "y"
 * Example 4:
 * Input: s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
 * Output: "abcdefghijklmnopqrstuvwxyz"
 * Constraints:
 * * 1 <= s.length <= 1000
 * * s[i] only contains digits letters ('0'-'9') and '#' letter.
 * * s will be valid string such that mapping is always possible.
 */

/**
 * 从右往左扫描，遇到'#'字符将前两位数字转成相应的字符，否则正常转换即可。
 */

class Solution {
    public:
        string freqAlphabets(string s) {
            std::stack<char> st;
            int idx = s.size() - 1;
            while (idx >= 0) {
                if (s[idx] == '#') {
                    assert(idx - 2 >= 0);
                    const int diff = (s[idx - 2] - '0') * 10 + (s[idx - 1] - '0');
                    assert(diff >= 10 && diff <= 26);
                    st.push('a' + diff - 1);
                    idx -= 3;
                } else {
                    st.push('a' + (s[idx] - '0') - 1);
                    --idx;
                }
            }
            string result(st.size(), '0');
            for (size_t i = 0; i < result.size(); ++i) {
                result[i] = st.top();
                st.pop();
            }
            assert(st.empty());
            return result;
        }
};
