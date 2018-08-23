/**
 * @file Kth-Largest-Element-in-a-Stream.cpp
 * @brief 流中第k大的元素(https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)
 * @author Finalcheat
 * @date 2018-08-21
 */

/**
 * Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 * Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element in the stream.
 * Example:
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 */

/**
 * 用最小堆记录前k大的元素，每次添加元素与最小堆最小的元素比较，如果比它大则替换同时维持最小堆，否则直接返回最小元素。
 */


class KthLargest {
    public:
        KthLargest(int k, vector<int> nums) : _k(k) {
            std::sort(nums.begin(), nums.end(), std::greater<int>());
            int minimum = std::min(k, (int)nums.size());
            ptMinHeap = new std::vector<int>(nums.begin(), nums.begin() + minimum);
            std::make_heap(ptMinHeap->begin(), ptMinHeap->end(), std::greater<int>());
        }

        int add(int val) {
            std::vector<int>& minHeap = *ptMinHeap;
            if (minHeap.size() < _k) {
                minHeap.push_back(val);
                push_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
            } else if (val > minHeap[0]) {
                minHeap[0] = val;
                std::make_heap(minHeap.begin(), minHeap.end(), std::greater<int>());
            }
            return minHeap[0];
        }

    private:
        std::vector<int>* ptMinHeap;
        int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
