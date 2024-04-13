/**
 * @file Find-The-Peaks.cpp
 * @brief 找出峰值(https://leetcode.com/problems/find-the-peaks/description/)
 * @author Finalcheat
 * @date 2024-04-13
 */


/**
 * 判断是否都大于相邻元素即可。
 */


class Solution {
    public:
        vector<int> findPeaks(vector<int>& mountain) {
            vector<int> res;
            for (int i = 1; i < mountain.size() - 1; ++i) {
                if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
                    res.push_back(i);
                }
            }
            return res;
        }
};
