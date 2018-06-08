/**
 * @file Student-Attendance-Record-I.cpp
 * @brief 学生考勤记录I(https://leetcode.com/problems/student-attendance-record-i/description/)
 * @author Finalcheat
 * @date 2018-01-22
 */

/**
 * You are given a string representing an attendance record for a student. The record only contains the following three characters:
 * 1. 'A' : Absent.
 * 2. 'L' : Late.
 * 3. 'P' : Present.
 * A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
 * You need to return whether the student could be rewarded according to his attendance record.
 * Example 1:
 * Input: "PPALLP"
 * Output: True
 * Example 2:
 * Input: "PPALLL"
 * Output: False
 */

/**
 * 遍历统计次数即可，注意题目要求L是连续出现大于两次。
 */


class Solution {
    public:
        bool checkRecord(string s) {
            size_t absentCount = 0;
            size_t lateCount = 0;
            for (size_t i = 0; i < s.size(); ++i) {
                const char c = s[i];
                if (c == 'A') {
                    ++absentCount;
                    lateCount = 0;
                } else if (c == 'L') {
                    ++lateCount;
                } else {
                    lateCount = 0;
                }
                if (absentCount > 1 || lateCount > 2) {
                    return false;
                }
            }
            return true;
        }
};
