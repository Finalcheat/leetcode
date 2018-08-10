/**
 * @file Reordered-Power-of-2.cpp
 * @brief 重新排序是否为2的幂(https://leetcode.com/problems/reordered-power-of-2/description/)
 * @author Finalcheat
 * @date 2018-08-06
 */

/**
 * Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.
 * Return true if and only if we can do this in a way such that the resulting number is a power of 2.
 * Example 1:
 * Input: 1
 * Output: true
 * Example 2:
 * Input: 10
 * Output: false
 * Example 3:
 * Input: 16
 * Output: true
 * Example 4:
 * Input: 24
 * Output: false
 * Example 5:
 * Input: 46
 * Output: true
 */

/**
 * 首先计算32bit下所有2的幂数字，将这些数字转成字符串，字符串按字典序排序存储到set中，最后对N做同样处理然后在set中搜索即可。
 */


class Solution {
    public:
        bool reorderedPowerOf2(int N) {
            std::unordered_set<std::string> u;
            for (size_t i = 0; i <= 32; ++i) {
                std::string num = std::to_string(1 << i);
                std::sort(num.begin(), num.end());
                u.insert(num);
            }
            std::string NNum = std::to_string(N);
            std::sort(NNum.begin(), NNum.end());
            const auto iter = u.find(NNum);
            return iter != u.end();
        }
};
