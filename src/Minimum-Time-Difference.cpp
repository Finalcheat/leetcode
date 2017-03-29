/**
 * @file Minimum-Time-Difference.cpp.cpp
 * @brief 时间值最小差值(https://leetcode.com/problems/minimum-time-difference/)
 * @author Finalcheat
 * @date 2017-03-29
 */

/**
 * Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
 * Example 1:
 * Input: ["23:59","00:00"]
 * Output: 1
 * Note:
 * 1. The number of time points in the given list is at least 2 and won't exceed 20000.
 * 2. The input time is legal and ranges from 00:00 to 23:59.
 */

/**
 * 考虑将时间值转换为数字，然后将数字排序，时间最小差值必定出现在相邻元素中(别忘了首尾之间的差值)。
 */

class Solution {
    public:
        int findMinDifference(vector<string>& timePoints) {
            if (timePoints.size() < 2) {
                return -1;
            }
            vector<int> timePointNumbers(timePoints.size());
            for (size_t i = 0; i < timePoints.size(); ++i) {
                timePointNumbers[i] = timePointToNumber(timePoints[i]);
            }
            std::sort(timePointNumbers.begin(), timePointNumbers.end());
            const int maxValue = 24 * 60;
            int minDiff = maxValue - (timePointNumbers[timePointNumbers.size() - 1] - timePointNumbers[0]);
            for (size_t i = 1; i < timePointNumbers.size(); ++i) {
                int diff = timePointNumbers[i] - timePointNumbers[i - 1];
                if (diff < minDiff) {
                    minDiff = diff;
                }
            }
            return minDiff;
        }
        
    private:
        int timePointToNumber(const string& timePoint) {
            size_t index = timePoint.find_first_of(":");
            int hour = std::stoi(timePoint.substr(0, index));
            int minute = std::stoi(timePoint.substr(index + 1, timePoint.size() - index - 1));
            return hour * 60 + minute;
        }
};
