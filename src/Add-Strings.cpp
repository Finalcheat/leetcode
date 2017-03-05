/**
 * @file Add-Strings.cpp
 * @brief 数字字符串相加(https://leetcode.com/problems/add-strings/)
 * @author Finalcheat
 * @date 2017-03-05
 */

/**
 * Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 * Note:
 * 1. The length of both num1 and num2 is < 5100.
 * 2. Both num1 and num2 contains only digits 0-9.
 * 3. Both num1 and num2 does not contain any leading zero.
 * 4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

/**
 * 从后往前遍历对每个字符进行相加得到新结果放到新字符串中，注意新字符串长度的确定以及最后的进位(如果有)的处理即可。
 */

class Solution {
    public:
        string addStrings(string num1, string num2) {
            int len1 = num1.size();
            int len2 = num2.size();
            int len3 = std::max(len1, len2);
            string result(len3, '0');
            int carry = 0;
            while (len1 || len2) {
                int n1 = 0;
                if (len1 > 0) {
                    n1 = num1[--len1] - '0';
                }
                int n2 = 0;
                if (len2 > 0) {
                    n2 = num2[--len2] - '0';
                }
                int sum = n1 + n2 + carry;
                carry = sum / 10;
                sum = sum % 10;
                result[--len3] += sum;
            }
            if (carry > 0) {
                return std::to_string(carry) + result;
            }
            return result;
        }
};
