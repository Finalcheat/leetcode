/**
 * @file Number-of-Students-Doing-Homework-at-a-Given-Time.cpp
 * @brief 在给定时间做作业的学生人数(https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/)
 * @author Finalcheat
 * @date 2020-05-23
 */

/**
 * Given two integer arrays startTime and endTime and given an integer queryTime.
 * The ith student started doing their homework at the time startTime[i] and finished it at time endTime[i].
 * Return the number of students doing their homework at time queryTime. More formally, return the number of students where queryTime lays in the interval [startTime[i], endTime[i]] inclusive.
 * Example 1:
 * Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
 * Output: 1
 * Explanation: We have 3 students where:
 * The first student started doing homework at time 1 and finished at time 3 and wasn't doing anything at time 4.
 * The second student started doing homework at time 2 and finished at time 2 and also wasn't doing anything at time 4.
 * The third student started doing homework at time 3 and finished at time 7 and was the only student doing homework at time 4.
 * Example 2:
 * Input: startTime = [4], endTime = [4], queryTime = 4
 * Output: 1
 * Explanation: The only student was doing their homework at the queryTime.
 * Example 3:
 * Input: startTime = [4], endTime = [4], queryTime = 5
 * Output: 0
 * Example 4:
 * Input: startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
 * Output: 0
 * Example 5:
 * Input: startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
 * Output: 5
 * Constraints:
 * * startTime.length == endTime.length
 * * 1 <= startTime.length <= 100
 * * 1 <= startTime[i] <= endTime[i] <= 1000
 * * 1 <= queryTime <= 1000
 */

/**
 * 遍历判断是否在区间内即可。
 */

class Solution {
    public:
        int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
            assert(startTime.size() == endTime.size());
            int count = 0;
            for (size_t i = 0; i < startTime.size(); ++i) {
                if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
                    ++count;
                }
            }
            return count;
        }
};
