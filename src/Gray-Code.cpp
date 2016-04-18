/**
 * @file Gray-Code.cpp
 * @brief 格雷码(https://leetcode.com/problems/gray-code/) 
 * @author Finalcheat
 * @date 2016-04-18
 */

/**
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 */

/**
 * 根据[格雷码](https://zh.wikipedia.org/wiki/%E6%A0%BC%E9%9B%B7%E7%A0%81)定义可得出计算公式。
 * （假设以二进制为0的值做为格雷码的0）
 * G：格雷码 B：二进制码
 * G(N) = (B(n)/2) XOR B(n)
 */

class Solution {
    public:
        vector<int> grayCode(int n) {
            int len = 1 << n;
            vector<int> result(len);
            for (size_t i = 0; i < len; ++i) {
                result[i] = (i / 2) ^ i;
            }
            return result;
        }
};
