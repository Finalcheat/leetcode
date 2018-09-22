/**
 * @file Non-overlapping-Intervals.cpp
 * @brief 无重叠区间(https://leetcode.com/problems/non-overlapping-intervals/description/)
 * @author Finalcheat
 * @date 2018-09-16
 */

/**
 * Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
 * Note:
 * 1. You may assume the interval's end point is always bigger than its start point.
 * 2. Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
 * Example 1:
 * Input: [ [1,2], [2,3], [3,4], [1,3] ]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
 * Example 2:
 * Input: [ [1,2], [1,2], [1,2] ]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
 * Example 3:
 * Input: [ [1,2], [2,3] ]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 */

/**
 * 跟合并区间类似，首先按start排序，遍历过程中发现prev.end > cur.start则说明区间重叠了，数量加1，同时删掉end较大那个。
 */


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    public:
        int eraseOverlapIntervals(vector<Interval>& intervals) {
            if (intervals.empty()) {
                return 0;
            }
            std::sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r) {
                if (l.start < r.start) {
                    return true;
                } else if (l.start == r.start) {
                    return l.end < r.end;
                }
                return false;
            });
            Interval prev = intervals[0];
            int count = 0;
            for (size_t i = 1; i < intervals.size(); ++i) {
                const Interval& in = intervals[i];
                if (prev.end > in.start) {
                    ++count;
                    if (in.end < prev.end) {
                        prev = in;
                    }
                } else {
                    prev = in;
                }
            }
            return count;
        }
};
