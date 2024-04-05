/**
 * @file Sort-Array-By-Parity-II.cpp
 * @brief 按奇偶排序数组II(https://leetcode.com/problems/sort-array-by-parity-ii)
 * @author Finalcheat
 * @date 2018-11-30
 */

/**
 * Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.
 * Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.
 * You may return any answer array that satisfies this condition.
 * Example 1:
 * Input: [4,2,5,7]
 * Output: [4,5,2,7]
 * Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 */

/**
 * 解法1:
 * 把奇偶数分离出去按位置摆放即可。
 * 解法2:
 * 双指针遍历交换
 */


/**
 * 解法1
 */
class Solution {
    public:
        vector<int> sortArrayByParityII(vector<int>& A) {
            vector<int> oddVector;
            vector<int> evenVector;
            for (size_t i = 0; i < A.size(); ++i) {
                if (A[i] % 2 == 0) {
                    evenVector.push_back(A[i]);
                } else {
                    oddVector.push_back(A[i]);
                }
            }
            assert(oddVector.size() == evenVector.size());
            vector<int> result(A.size());
            vector<int>::const_iterator oddIter = oddVector.begin();
            vector<int>::const_iterator evenIter = evenVector.begin();
            for (size_t i = 0; i < result.size(); ++i) {
                if (i % 2 == 0) {
                    result[i] = *evenIter++;
                } else {
                    result[i] = *oddIter++;
                }
            }
            return result;
        }
};


/**
 * 解法2
 */
class Solution {
    public:
        vector<int> sortArrayByParityII(vector<int>& nums) {
            if (nums.empty()) {
                return nums;
            }
            int first = 0;
            int last = nums.size() - 1;
            while (first < last) {
                while (first < last && (isOdd(nums[first], first) || isEven(nums[first], first))) {
                    ++first;
                }
                if (first >= last) {
                    break;
                }
                if (first % 2 == 0) {
                    int last_i = last;
                    while (first < last_i && (nums[last_i] % 2 != 0)) {
                        --last_i;
                    }
                    std::swap(nums[first], nums[last_i]);
                    ++first;
                } else {
                    int last_ii = last;
                    while (first < last_ii && (nums[last_ii] % 2 == 0)) {
                        --last_ii;
                    }
                    std::swap(nums[first], nums[last_ii]);
                    ++first;
                }
            }
            return nums;
        }
    private:
        bool isOdd(const int num, const int idx) {
            return (num % 2 != 0) && (idx % 2 != 0);
        }
        bool isEven(const int num, const int idx) {
            return (num % 2 == 0) && (idx % 2 == 0);
        }
};
