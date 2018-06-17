/**
 * @file Reconstruct-Original-Digits-from-English.cpp
 * @brief 从英文中重建数字(https://leetcode.com/problems/reconstruct-original-digits-from-english/description/)
 * @author Finalcheat
 * @date 2018-06-17
 */

/**
 * Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
 * Note:
 * 1. Input contains only lowercase English letters.
 * 2. Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
 * 3. Input length is less than 50,000.
 * Example 1:
 * Input: "owoztneoer"
 * Output: "012"
 * Example 2:
 * Input: "fviefuro"
 * Output: "45"
 */

/**
 * 首先有些单词的某个字符是独一无二的，利用这个作为突破点确定几个单词的数量，然后其他单词就可以推出来了。
 */


class Solution {
    public:
        string originalDigits(string s) {
            vector<int> v(26, 0);
            for (size_t i = 0; i < s.size(); ++i) {
                const size_t idx = s[i] - 'a';
                assert(idx >= 0 && idx < 26);
                ++v[idx];
            }

            vector<int> nums(10, 0);
            nums[0] = v['z' - 'a'];
            nums[2] = v['w' - 'a'];
            nums[4] = v['u' - 'a'];
            nums[6] = v['x' - 'a'];
            nums[8] = v['g' - 'a'];
            nums[1] = v['o' - 'a'] - nums[0] - nums[2] - nums[4];
            nums[3] = v['h' - 'a'] - nums[8];
            nums[5] = v['f' - 'a'] - nums[4];
            nums[7] = v['s' - 'a'] - nums[6];
            nums[9] = v['i' - 'a'] - nums[6] - nums[8] - nums[5];

            string result;
            for (size_t i = 0; i < nums.size(); ++i) {
                const size_t numCount = nums[i];
                string numStr;
                numStr.resize(numCount, '0');
                for (size_t j = 0; j < numCount; ++j) {
                    numStr[j] += i;
                }
                result += numStr;
            }

            return result;
        }
};
