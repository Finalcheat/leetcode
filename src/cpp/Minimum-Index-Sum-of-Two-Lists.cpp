/**
 * @file Minimum-Index-Sum-of-Two-Lists.cpp
 * @brief 两个数组的最小坐标和(https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/)
 * @author Finalcheat
 * @date 2018-01-14
 */

/**
 * Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.
 * ou need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.
 * Example 1:
 * Input:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
 * Output: ["Shogun"]
 * Explanation: The only restaurant they both like is "Shogun".
 * Example 2:
 * Input:
 * ["Shogun", "Tapioca Express", "Burger King", "KFC"]
 * ["KFC", "Shogun", "Burger King"]
 * Output: ["Shogun"]
 * Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
 */

/**
 * 遍历list1将字符串与坐标值用hash table建立对应关系，然后遍历list2查找判断即可。
 */


class Solution {
    public:
        vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
            std::unordered_map<string, size_t> u;
            for (size_t i = 0; i < list1.size(); ++i) {
                u.insert(std::make_pair(list1[i], i));
            }
            size_t sum = list1.size() + list2.size();
            vector<string> result;
            for (size_t i = 0; i < list2.size(); ++i) {
                const string& s = list2[i];
                std::unordered_map<string, size_t>::const_iterator it = u.find(s);
                if (it != u.end()) {
                    if (it->second + i < sum) {
                        sum = it->second + i;
                        result.clear();
                        result.push_back(it->first);
                    } else if (it->second + i == sum) {
                        result.push_back(it->first);
                    }
                }
            }
            return result;
        }
};
