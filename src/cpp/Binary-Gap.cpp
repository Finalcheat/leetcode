/**
 * @file Binary-Gap.cpp
 * @brief 二进制间距(https://leetcode.com/problems/binary-gap/description/)
 * @author Finalcheat
 * @date 2018-08-25
 */

/**
 * Given a positive integer N, find and return the longest distance between two consecutive 1's in the binary representation of N.
 * If there aren't two consecutive 1's, return 0.
 * Example 1:
 * Input: 22
 * Output: 2
 * Explanation:
 * 22 in binary is 0b10110.
 * In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
 * The first consecutive pair of 1's have distance 2.
 * The second consecutive pair of 1's have distance 1.
 * The answer is the largest of these two distances, which is 2.
 * Example 2:
 * Input: 5
 * Output: 2
 * Explanation:
 * 5 in binary is 0b101.
 * Example 3:
 * Input: 6
 * Output: 1
 * Explanation:
 * 6 in binary is 0b110.
 * Example 4:
 * Input: 8
 * Output: 0
 * Explanation:
 * 8 in binary is 0b1000.
 * There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.
 */

/**
 * 取出1的位置判断即可，注意细节就行了没什么难度。
 */


class Solution {
    public:
        int binaryGap(int N) {
            int n = N;
            int idx = 0;
            int maximum = 0;
            int oneCount = 0;
            while (n) {
                int bit = n & 1;
                ++idx;
                if (bit == 1) {
                    ++oneCount;
                    if (oneCount == 2) {
                        oneCount = 1;
                        if (idx > maximum) {
                            maximum = idx;
                        }
                    }
                    idx = 0;
                }
                n >>= 1;
            }
            return maximum;
        }
};
