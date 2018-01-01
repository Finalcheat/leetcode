/**
 * @file Self-Dividing-Numbers.cpp
 * @brief 自整除数字(https://leetcode.com/problems/self-dividing-numbers/description/)
 * @author Finalcheat
 * @date 2018-01-01
 */

/**
 * A self-dividing number is a number that is divisible by every digit it contains
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 * Also, a self-dividing number is not allowed to contain the digit zero.
 * Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
 * Example 1:
 * Input:
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * Note:
 * The boundaries of each input argument are 1 <= left <= right <= 10000.
 */

/**
 * 遍历分离出各位数字筛选判断即可，注意判断0的存在。
 */


class Solution {
    public:
        vector<int> selfDividingNumbers(int left, int right) {
            vector<int> result;
            for (; left <= right; ++left) {
                if (left % 10 == 0) {
                    continue;
                }
                bool find = true;
                int num = left;
                int remainder;
                while ((remainder = num % 10) > 0) {
                    num /= 10;
                    if (left % remainder != 0) {
                        find = false;
                        break;
                    }
                }
                if (find == true && num < 10) {
                    result.push_back(left);
                }
            }
            return result;
        }
};
