/**
 * @file Pancake-Sorting.cpp
 * @brief 煎饼排序(https://leetcode.com/problems/pancake-sorting/)
 * @author Finalcheat
 * @date 2019-02-18
 */

/**
 * Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips (doing them one after another in succession) to sort the array A.
 * Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer that sorts the array within 10 * A.length flips will be judged as correct.
 * Example 1:
 * Input: [3,2,4,1]
 * Output: [4,2,4,3]
 * Explanation:
 * We perform 4 pancake flips, with k values 4, 2, 4, and 3.
 * Starting state: A = [3, 2, 4, 1]
 * After 1st flip (k=4): A = [1, 4, 2, 3]
 * After 2nd flip (k=2): A = [4, 1, 2, 3]
 * After 3rd flip (k=4): A = [3, 2, 1, 4]
 * After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted.
 * Example 2:
 * Input: [1,2,3]
 * Output: []
 * Explanation: The input is already sorted, so there is no need to flip anything.
 * Note that other answers, such as [3, 3], would also be accepted.
 */

/**
 * 煎饼排序，最简单的方法每次找出当前最大的值翻转到最前面后再翻转一次移到后面。
 */


class Solution {
    public:
        vector<int> pancakeSort(vector<int>& A) {
            vector<int> aCopy(A);
            std::sort(aCopy.begin(), aCopy.end());
            vector<int> result;
            for (int n = A.size() - 1; n > 0; --n) {
                int curMax = aCopy[n];
                vector<int>::iterator iter = std::find(A.begin(), A.begin() + n, curMax);
                assert(iter != A.end());
                if (iter == A.begin()) {
                    result.push_back(n + 1);
                    std::reverse(A.begin(), A.begin() + n + 1);
                    continue;
                }
                ++iter;
                if (iter == A.end()) {
                    continue;
                }
                result.push_back(iter - A.begin());
                std::reverse(A.begin(), iter);
                result.push_back(n + 1);
                std::reverse(A.begin(), A.begin() + n + 1);
            }

            return result;
        }
};
