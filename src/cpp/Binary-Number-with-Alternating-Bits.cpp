/**
 * @file Binary-Number-with-Alternating-Bits.cpp
 * @brief 交替位的二进制数(https://leetcode.com/problems/binary-number-with-alternating-bits/)
 * @author Finalcheat
 * @date 2017-10-21
 */

/**
 * Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
 * Example 1:
 * Input: 5
 * Output: True
 * Explanation:
 * The binary representation of 5 is: 101
 * Example 2:
 * Input: 7
 * Output: False
 * Explanation:
 * The binary representation of 7 is: 111.
 * Example 3:
 * Input: 11
 * Output: False
 * Explanation:
 * The binary representation of 11 is: 1011.
 * Example 4:
 * Input: 10
 * Output: True
 * Explanation:
 * The binary representation of 10 is: 1010.
 */

/**
 * 取二进制位过程中判断即可。
 */

class Solution {
    public:
        bool hasAlternatingBits(int n) {
            int bit = n % 2;
            n /= 2;
            while (n > 0) {
                bit = !bit;
                if (n % 2 != bit) {
                    return false;
                }
                n /= 2;
            }
            return true;
        }
};
