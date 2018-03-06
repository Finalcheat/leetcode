/**
 * @file String-Compression.cpp
 * @brief 字符串压缩(https://leetcode.com/problems/string-compression/description/)
 * @author Finalcheat
 * @date 2018-03-06
 */

/**
 * Given an array of characters, compress it in-place.
 * The length after compression must always be smaller than or equal to the original array.
 * Every element of the array should be a character (not int) of length 1.
 * After you are done modifying the input array in-place, return the new length of the array.
 * Follow up:
 * Could you solve it using only O(1) extra space?
 * Example 1:
 * Input:
 * ["a","a","b","b","c","c","c"]
 * Output:
 * Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
 * Explanation:
 * "aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
 * Example 2:
 * Input:
 * ["a"]
 * Output:
 * Return 1, and the first 1 characters of the input array should be: ["a"]
 * Explanation:
 * Nothing is replaced.
 * Example 3:
 * Input:
 * ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * Output:
 * Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
 * Explanation:
 * Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
 * Notice each digit has it's own entry in the array.
 * Note:
 * 1. All characters have an ASCII value in [35, 126].
 * 2. 1 <= len(chars) <= 1000.
 */

/**
 * 使用三个变量pos、cnt、lastChar分别记录当前处理位置、连续字符出现次数、上一次字符，遍历过程中判断并修改即可。
 * 注意次数大于等于10后转化成字符的问题，这里直接用std::to_string转，也可以自己实现。
 */


class Solution {
    public:
        int compress(vector<char>& chars) {
            if (chars.empty()) {
                return 0;
            }
            int pos = 1;
            int cnt = 1;
            char lastChar = chars[0];
            for (size_t i = 1; i < chars.size(); ++i) {
                const char c = chars[i];
                if (c == lastChar) {
                    ++cnt;
                } else {
                    chars[pos] = c;
                    lastChar = c;
                    cnt = 1;
                }
                if (cnt > 1) {
                    while (i + 1 < chars.size() && chars[i] == chars[i + 1]) {
                        ++cnt;
                        ++i;
                    }
                    if (cnt > 9) {
                        const std::string cntStr = std::to_string(cnt);
                        for (size_t j = 0; j < cntStr.size(); ++j) {
                            chars[pos] = cntStr[j];
                            ++pos;
                        }
                        --pos;
                    } else {
                        chars[pos] = '0' + cnt;
                    }
                }
                ++pos;
            }
            return pos;
        }
};
