/**
 * @file Set-Mismatch.cpp
 * @brief 寻找Set丢失值(https://leetcode.com/problems/set-mismatch/description/)
 * @author Finalcheat
 * @date 2018-02-28
 */

/**
 * The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.
 * Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 */

/**
 * 用hashtable得到重复的数字，利用求和公式得到正确的和，然后减去实际的累计值得到差值，最后加上重复的数字值就是丢失的值。
 */


class Solution {
    public:
        vector<int> findErrorNums(vector<int>& nums) {
            const size_t size = nums.size();
            int nSum = (1 + size) * size / 2;
            int sum = 0;
            std::unordered_set<int> u;
            vector<int> result;
            for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
                sum += *it;
                if (result.empty() && u.find(*it) != u.end()) {
                    result.push_back(*it);
                } else {
                    u.insert(*it);
                }
            }
            if (!result.empty()) {
                result.push_back(result[0] + (nSum - sum));
            }
            return result;
        }
};
