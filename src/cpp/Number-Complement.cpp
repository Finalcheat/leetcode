/**
 * @file Number-Complement.cpp
 * @brief 补码(https://leetcode.com/problems/number-complement/)
 * @author Finalcheat
 * @date 2017-02-13
 */

/**
 * Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.
 * Note:
 * 1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * 2. You could assume no leading zero bit in the integer’s binary representation.
 * Example 1:
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 * Example 2:
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 */

/**
 * 将各个bit取反即可。
 */

class Solution {
    public:
        int findComplement(int num) {
            int result = 0;
            int n = 0;
            while (num) {
                int bit = num & 1;
                bit = !bit;
                result |= (bit << n);
                num = num >> 1;
                ++n;
            }
            return result;
        }
};
