/**
 * @file Task-Scheduler.cpp
 * @brief 任务调度(https://leetcode.com/problems/task-scheduler/description/)
 * @author Finalcheat
 * @date 2018-03-25
 */

/**
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 * Example 1:
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * Note:
 * 1. The number of tasks is in the range [1, 10000].
 * 2. The integer n is in the range [0, 100].
 */

/**
 * 基本思路是算出出现次数最多的元素，然后将出现次数最多的元素间隔n个位置，最后一组另外计算
 * result = (maxCount - 1) * (n + 1) + maxCountRep
 * 另外要注意n=0的情况以及result<tasks.size()的情况
 */


class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            std::map<char, size_t> m;
            for (const auto& task : tasks) {
                ++m[task];
            }
            size_t maxCount = 0;
            size_t maxCountRep = 0;
            for (const auto& pair : m) {
                const size_t count = pair.second;
                if (count > maxCount) {
                    maxCount = count;
                    maxCountRep = 1;
                } else if (count == maxCount) {
                    ++maxCountRep;
                }
            }
            const int result = std::max(tasks.size(), (maxCount - 1) * (n + 1) + maxCountRep);
            return result;
        }
};
