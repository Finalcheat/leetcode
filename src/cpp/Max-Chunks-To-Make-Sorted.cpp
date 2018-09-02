/**
 * @file Max-Chunks-To-Make-Sorted.cpp
 * @brief 最大块排序(https://leetcode.com/problems/max-chunks-to-make-sorted/description/)
 * @author Finalcheat
 * @date 2018-07-23
 */

/**
 * Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.
 * What is the most number of chunks we could have made?
 * Example 1:
 * Input: arr = [4,3,2,1,0]
 * Output: 1
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
 * Example 2:
 * Input: arr = [1,0,2,3,4]
 * Output: 4
 * Explanation:
 * We can split into two chunks, such as [1, 0], [2, 3, 4].
 * However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
 */

/**
 * 找切分点，注意到某位置元素最大值等于当前位置索引，则可以作为一个切分点。
 */


class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
            int count = 0;
            int maximum = 0;
            for (size_t i = 0; i < arr.size(); ++i) {
                maximum = std::max(maximum, arr[i]);
                if (maximum == i) {
                    ++count;
                }
            }
            return count;
        }
};
