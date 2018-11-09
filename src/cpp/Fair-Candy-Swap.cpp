/**
 * @file Fair-Candy-Swap.cpp
 * @brief 公平交换糖果(https://leetcode.com/problems/fair-candy-swap/description/)
 * @author Finalcheat
 * @date 2018-11-04
 */

/**
 * Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.
 * Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)
 * Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.
 * If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.
 * Example 1:
 * Input: A = [1,1], B = [2,2]
 * Output: [1,2]
 * Example 2:
 * Input: A = [1,2], B = [2,3]
 * Output: [1,2]
 * Example 3:
 * Input: A = [2], B = [1,3]
 * Output: [2,3]
 * Example 4:
 * Input: A = [1,2,5], B = [2,4]
 * Output: [5,4]
 */

/**
 * 算出差值除以2，最后遍历数组找值即可。
 */


class Solution {
    public:
        vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
            int sumA = 0;
            for (const int num : A) {
                sumA += num;
            }
            int sumB = 0;
            std::unordered_set<int> u;
            for (const int num : B) {
                sumB += num;
                u.insert(num);
            }
            int dist = (sumB - sumA) / 2;
            vector<int> result(2);
            for (const int num : A) {
                const int n = num + dist;
                const auto iter = u.find(n);
                if (iter != u.end()) {
                    result[0] = num;
                    result[1] = n;
                    break;
                }
            }
            return result;
        }
};
