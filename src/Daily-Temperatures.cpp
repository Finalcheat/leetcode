/**
 * @file Daily-Temperatures.cpp
 * @brief 每日温度(https://leetcode.com/problems/daily-temperatures/description/)
 * @author Finalcheat
 * @date 2018-03-19
 */

/**
 * Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
 * For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
 */

/**
 * 用hashtable保存元素的下标位置，然后遍历找到比当前位置大的最小位置。
 */


class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            std::map<int, std::vector<size_t>> m;
            for (size_t i = 0; i < temperatures.size(); ++i) {
                const int value = temperatures[i];
                auto iter = m.find(value);
                if (iter == m.end()) {
                    std::vector<size_t> idxs;
                    idxs.push_back(i);
                    m[value] = idxs;
                } else {
                    std::vector<size_t>& idxs = iter->second;
                    idxs.push_back(i);
                }
            }
            std::vector<int> result(temperatures.size(), 0);
            for (size_t i = 0; i < temperatures.size(); ++i) {
                const int value = temperatures[i];
                auto iter = m.upper_bound(value);
                size_t minIndex = temperatures.size();
                while (iter != m.end()) {
                    const std::vector<size_t>& idxs = iter->second;
                    auto idxIter = std::upper_bound(idxs.begin(), idxs.end(), i);
                    if (idxIter != idxs.end() && *idxIter < minIndex) {
                        minIndex = *idxIter;
                    }
                    ++iter;
                }
                if (minIndex != temperatures.size()) {
                    result[i] = minIndex - i;
                }
            }
            return result;
        }
};
