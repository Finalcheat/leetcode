/**
 * @file Merge-Intervals.cpp
 * @brief 合并区间(https://leetcode.com/problems/merge-intervals/description/)
 * @author Finalcheat
 * @date 2018-09-11
 */

/**
 * Given a collection of intervals, merge all overlapping intervals.
 * Example 1:
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 * Example 2:
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
 */

/**
 * 首先按start排序，然后遍历过程中前一个区间end与当前区间start对比，如果end较小，说明区间不可合并，否则合并区间。
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
        vector<Interval> merge(vector<Interval>& intervals) {
            if (intervals.empty()) {
                return intervals;
            }
            std::sort(intervals.begin(), intervals.end(), [](const Interval& l, const Interval& r) {
                    return l.start < r.start;
                });
            Interval prev = intervals[0];
            vector<Interval> result;
            for (size_t i = 1; i < intervals.size(); ++i) {
                const Interval& in = intervals[i];
                if (prev.end < in.start) {
                    result.push_back(prev);
                    prev = in;
                } else {
                    prev.end = std::max(prev.end, in.end);
                }
            }
            result.push_back(prev);
            return result;
        }
};
