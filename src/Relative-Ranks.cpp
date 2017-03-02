/**
 * @file Relative-Ranks.cpp
 * @brief 相对排名(https://leetcode.com/problems/relative-ranks)
 * @author Finalcheat
 * @date 2017-03-02
 */

/**
 * Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
 * Example 1:
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
 * For the left two athletes, you just need to output their relative ranks according to their scores.
 * Note:
 * 1. N is a positive integer and won't exceed 10,000.
 * 2. All the scores of athletes are guaranteed to be unique.
 */

/**
 * 使用结构体保存每个分数的值以及在原数组的位置构成新数组，按照分数排序新数组，最后遍历新数组得到每个分数值的原位置进行输出即可。
 */

class Solution {
    protected:
        struct Rank {
            Rank(const size_t _i, const int _s) : index(_i), scores(_s) {}
            size_t index;
            int scores;
        };
    public:
        vector<string> findRelativeRanks(vector<int>& nums) {
            vector<Rank> ranks;
            for (size_t i = 0; i < nums.size(); ++i) {
                ranks.push_back(Rank(i, nums[i]));
            }
            std::sort(ranks.begin(), ranks.end(), [](const Rank& l, const Rank& r) {
                return l.scores > r.scores;
            });
            vector<string> result(ranks.size());
            for (size_t i = 0; i < ranks.size(); ++i) {
                const size_t index = ranks[i].index;
                if (i >= 3) {
                    result[index] = std::to_string(i + 1);
                } else if (i == 2) {
                    result[index] = "Bronze Medal";
                } else if (i == 1) {
                    result[index] = "Silver Medal";
                } else {
                    result[index] = "Gold Medal";
                }
            }
            return result;
        }
};
