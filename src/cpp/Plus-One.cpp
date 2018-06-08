/**
 * @file Plus-One.cpp
 * @brief 数组加一(https://leetcode.com/problems/plus-one/) 
 * @author Finalcheat
 * @date 2016-05-12
 */

/**
 * Given a non-negative number represented as an array of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 */

/**
 * 模拟人类计算的方式即可，从低位开始加并记录进位，若进位为0，则直接返回；最后还有进位的话需要重新生成数组(原数组长度+1)。
 */

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int carry = 1;
            for (int i = digits.size() - 1; i >= 0; --i) {
                int num = digits[i] + carry;
                carry = num / 10;
                digits[i] = num % 10;
                if (carry == 0) {
                    return digits;
                }
            }
            std::vector<int> result(digits.size() + 1);
            std::copy(digits.begin() + 1, digits.end(), result.begin());
            result[0] = 1;
            return result; 
        }
};
