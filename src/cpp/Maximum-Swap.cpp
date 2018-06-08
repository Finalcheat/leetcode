/**
 * @file Maximum-Swap.cpp
 * @brief 最大置换(https://leetcode.com/problems/maximum-swap/description/)
 * @author Finalcheat
 * @date 2018-03-26
 */

/**
 * Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
 * Example 1:
 * Input: 2736
 * Output: 7236
 * Explanation: Swap the number 2 and the number 7.
 * Example 2:
 * Input: 9973
 * Output: 9973
 * Explanation: No swap.
 */

/**
 * 分拆各个数字，找出最大值查看前面是否还有比它小的数字，若有则交换，否则继续找次大值，以此类推。
 */


class Solution {

    public:
        int maximumSwap(int num) {
            int tmpNum = num;
            vector<int> vNum;
            while (tmpNum) {
                const int remainder = tmpNum % 10;
                tmpNum /= 10;
                vNum.push_back(remainder);
            }
            std::reverse(vNum.begin(), vNum.end());
            vector<int> buckets(10, -1);
            for (int i = 0; i < vNum.size(); ++i) {
                buckets[vNum[i]] = i;
            }

            for (int i = 0; i < vNum.size(); ++i) {
                const int idxNum = vNum[i];
                for (int j = 9; j > idxNum; --j) {
                    if (buckets[j] > i) {
                        std::swap(vNum[i], vNum[buckets[j]]);
                        const int result = vectorToNum(vNum);
                        return result;
                    }
                }
            }
            return num;
        }

    private:
        int vectorToNum(const vector<int>& v) {
            int sum = 0;
            for (size_t i = 0; i < v.size(); ++i) {
                sum *= 10;
                sum += v[i];
            }
            return sum;
        }

};
