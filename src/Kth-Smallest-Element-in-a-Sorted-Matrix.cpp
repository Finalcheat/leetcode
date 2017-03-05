/**
 * @file Kth-Smallest-Element-in-a-Sorted-Matrix.cpp
 * @brief 已排序的矩阵中第k小的元素(https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
 * @author Finalcheat
 * @date 2017-03-05
 */

/**
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * Example:
 * matrix = [
 *    [ 1,  5,  9],
 *    [10, 11, 13],
 *    [12, 13, 15]
 * ],
 * k = 8,
 * return 13.
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n2.
 */

/**
 * 构造一个k-1个元素的最小堆，而第k个位置保存当前第k个最小元素，遍历过程中发现有比k小的则替换然后重新构造最小堆，最后第k个位置保存的值就是第k小的元素了。
 */

class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            if (matrix.empty()) {
                return -1;
            }
            auto cmp = [](const int& l, const int& r) { return l < r; };
            vector<int> heap;
            int heapNum = 0;
            for (size_t i = 0; i < matrix.size(); ++i) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                    if (heapNum == k - 1) {
                        heap.push_back(matrix[i][j]);
                        std::push_heap(heap.begin(), heap.end(), cmp);
                        std::pop_heap(heap.begin(), heap.end(), cmp);
                        ++heapNum;
                    } else if (heapNum < k) {
                        heap.push_back(matrix[i][j]);
                        std::push_heap(heap.begin(), heap.end(), cmp);
                        ++heapNum;
                    } else {
                        if (matrix[i][j] < heap[k - 1]) {
                            heap[k - 1] = matrix[i][j];
                            std::push_heap(heap.begin(), heap.end(), cmp);
                            std::pop_heap(heap.begin(), heap.end(), cmp);
                        } else {
                            break;
                        }
                    }
                }
            }
            return heap[k - 1];
        }
};
