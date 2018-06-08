/**
 * @file Valid-Triangle-Number.cpp
 * @brief 有效的三角形边长(https://leetcode.com/problems/valid-triangle-number/description/)
 * @author Finalcheat
 * @date 2018-06-07
 */

/**
 * Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
 * Example 1:
 * Input: [2,2,3,4]
 * Output: 3
 * Explanation:
 * Valid combinations are:
 * 2,3,4 (using the first 2)
 * 2,3,4 (using the second 2)
 * 2,2,3
 */

/**
 * 一个三角形中，任意两边之和大于第三边，任意两边之差小于第三边。
 * 利用这个规则循环遍历即可，先排序可减少遍历次数。
 */


class Solution {
    public:
        int triangleNumber(vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            int count = 0;
            for (size_t i = 0; i < nums.size(); ++i) {
                int first = nums[i];
                for (size_t j = i + 1; j < nums.size(); ++j) {
                    int second = nums[j];
                    for (size_t k = j + 1; k < nums.size(); ++k) {
                        int third = nums[k];

                        if ((first + second) <= third) {
                            continue;
                        }

                        if (std::abs(first - third) >= second) {
                            break;
                        }

                        ++count;
                    }
                }
            }
            return count;
        }
};
