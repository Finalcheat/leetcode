/**
 * @file Find-Numbers-with-Even-Number-of-Digits.cpp
 * @brief 找出偶数位数的数值(https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)
 * @author Finalcheat
 * @date 2020-04-24
 */

/**
 * Given an array nums of integers, return how many of them contain an even number of digits.
 * Example 1:
 * Input: nums = [12,345,2,6,7896]
 * Output: 2
 * Explanation:
 * 12 contains 2 digits (even number of digits).
 * 345 contains 3 digits (odd number of digits).
 * 2 contains 1 digit (odd number of digits).
 * 6 contains 1 digit (odd number of digits).
 * 7896 contains 4 digits (even number of digits).
 * Therefore only 12 and 7896 contain an even number of digits.
 * Example 2:
 * Input: nums = [555,901,482,1771]
 * Output: 1
 * Explanation:
 * Only 1771 contains an even number of digits.
 */

/**
 * 按规则遍历统计即可。
 */

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int result = 0;
            for (const int num : nums) {
                if (numberOfDigits(num) % 2 == 0) {
                    ++result;
                }
            }
            return result;
        }
    private:
        int numberOfDigits(int number) {
            int count = 0;
            while (number) {
                ++count;
                number /= 10;
            }
            return count;
        }
};
