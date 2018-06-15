/**
 * @file Different-Ways-to-Add-Parentheses.cpp
 * @brief 添加括号的不同方式(https://leetcode.com/problems/different-ways-to-add-parentheses/description/)
 * @author Finalcheat
 * @date 2018-06-15
 */

/**
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
 * Example 1:
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Example 2:
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 */

/**
 * 第一时间想到的就应该是递归解决，首先考虑最简单的例子"2-1-1"
 * 以第一个-号为分割点，分成2和1-1，右边的1-1作为一个整体再次递归，得到的结果是2-0=2
 * 以第二个-号为分割点，分成2-1和1，左边的2-1作为一个整体再次递归，得到的结果是1-1=0
 * 所以思路就是遇到+-*号作为分割点，分别对左右部分递归求值，最后对左右值组合起来运算即可。
 */


class Solution {
    public:
        vector<int> diffWaysToCompute(const string& input) {
            std::vector<int> result;
            for (size_t i = 0; i < input.size(); ++i) {
                const char c = input[i];
                if (c == '+' || c == '-' || c == '*') {
                    std::string leftStr = input.substr(0, i);
                    std::string rightStr = input.substr(i + 1);
                    std::vector<int> left = diffWaysToCompute(leftStr);
                    std::vector<int> right = diffWaysToCompute(rightStr);
                    for (size_t j = 0; j < left.size(); ++j) {
                        for (size_t k = 0; k < right.size(); ++k) {
                            switch (c) {
                                case '+':
                                    result.push_back(left[j] + right[k]);
                                    break;
                                case '-':
                                    result.push_back(left[j] - right[k]);
                                    break;
                                case '*':
                                    result.push_back(left[j] * right[k]);
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                }
            }
            if (result.empty()) {
                result.push_back(std::stoi(input));
            }
            return result;
        }
};
