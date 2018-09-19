/**
 * @file Queue-Reconstruction-by-Height.cpp
 * @brief 根据身高重建队列(https://leetcode.com/problems/queue-reconstruction-by-height/description/)
 * @author Finalcheat
 * @date 2018-09-13
 */

/**
 * Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 * Example
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 */

/**
 * 首先按照k降序排序(h一样的情况下按k升序排序)，然后遍历排序结果插入到位置reuslt.begin() + p.second上即可。
 */


class Solution {
    public:
        vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
            std::sort(people.begin(), people.end(), [](const pair<int, int>& l, const pair<int, int>& r) {
                    if (l.first > r.first) {
                        return true;
                    } else if (l.first == r.first) {
                        return l.second < r.second;
                    }
                    return false;
                });
            vector< pair<int, int> > result;
            for (const auto& p : people) {
                result.insert(result.begin() + p.second, p);
            }
            return result;
        }
};
