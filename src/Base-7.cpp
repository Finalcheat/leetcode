/**
 * @file Base-7.cpp
 * @brief 七进制(https://leetcode.com/problems/base-7/)
 * @author Finalcheat
 * @date 2017-03-04
 */

/**
 * Given an integer, return its base 7 string representation.
 * Example 1:
 * Input: 100
 * Output: "202"
 * Example 2:
 * Input: -7
 * Output: "-10"
 * Note: The input will be in range of [-1e7, 1e7].
 */

/**
 * 按照进制转换的方法转换即可，注意负数的情况。
 */

class Solution {
    public:
        string convertToBase7(int num) {
            bool negative = num < 0 ? true : false;
            num = abs(num);
            std::stack<int> s;
            while (num) {
                s.push(num % 7);
                num = num / 7;
            }
            int result = 0;
            while (!s.empty()) {
                result *= 10;
                result += s.top();
                s.pop();
            }
            if (negative) {
                return "-" + std::to_string(result);
            }
            return std::to_string(result);
        }
};
