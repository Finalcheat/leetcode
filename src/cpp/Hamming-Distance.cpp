/**
 * @file Hamming-Distance.cpp
 * @brief 汉明距离(https://leetcode.com/problems/hamming-distance/)
 * @author Finalcheat
 * @date 2017-02-15
 */

/**
 * Given two strings s and t which consist of only lowercase letters.
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * Given two integers x and y, calculate the Hamming distance.
 * Note:
 * 0 ≤ x, y < 231.
 * Example:
 * Input: x = 1, y = 4
 * Output: 2
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
 * The above arrows point to positions where the corresponding bits are different.
 */

/**
 * 距离等于x与y异或得到的数二进制中1的个数。
 */

class Solution {
    public:
        int hammingDistance(int x, int y) {
            int result = 0;
            int num = x ^ y;
            while (num) {
                ++result;
                num &= num - 1;
            }
            return result;
        }
};
