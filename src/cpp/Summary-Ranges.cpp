/**
 * @file Summary-Ranges.cpp
 * @brief 总结区间(https://leetcode.com/problems/summary-ranges/) 
 * @author Finalcheat
 * @date 2016-06-20
 */

/**
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

/**
 * 循环过程中找出区间的起始和结尾构造字符串就可以了，比较简单。
 */

class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            std::vector<std::string> result;
            for (size_t i = 0; i < nums.size(); ++i) {
                int num = nums[i];
                const int start = i;
                while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
                    ++i;
                }
                if (i < nums.size() && start != i) {
                    std::string s = std::to_string(nums[start]) + "->" + std::to_string(nums[i]);
                    result.push_back(s);
                } else {
                    result.push_back(std::to_string(nums[start]));
                }
            }
            return result;
        }
};
