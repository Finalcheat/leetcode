/**
 * @file Find-N-Unique-Integers-Sum-up-to-Zero.cpp
 * @brief 求N个唯一整数的和为0(https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/)
 * @author Finalcheat
 * @date 2020-04-13
 */

/**
 * Given an integer n, return any array containing n unique integers such that they add up to 0.
 * Example 1:
 * Input: n = 5
 * Output: [-7,-1,1,3,4]
 * Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
 * Example 2:
 * Input: n = 3
 * Output: [-1,0,1]
 * Example 3:
 * Input: n = 1
 * Output: [0]
 */

/**
 * 偶数正负抵消，奇数添加0。
 */

class Solution {
    public:
        vector<int> sumZero(int n) {
            vector<int> result(n, 0);
            for (int i = 1; i < n; i += 2) {
                result[i - 1] = i;
                result[i] = -i;
            }
            return result;
        }
};
