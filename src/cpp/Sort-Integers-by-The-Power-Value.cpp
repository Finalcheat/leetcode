/**
 * @file Sort-Integers-by-The-Power-Value.cpp
 * @brief 根据幂值对整数排序(https://leetcode.com/problems/sort-integers-by-the-power-value/)
 * @author Finalcheat
 * @date 2020-04-18
 */

/**
 * The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:
 * * if x is even then x = x / 2
 * * if x is odd then x = 3 * x + 1
 * For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
 * Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.
 * Return the k-th integer in the range [lo, hi] sorted by the power value.
 * Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in 32 bit signed integer.
 * Example 1:
 * Input: lo = 12, hi = 15, k = 2
 * Output: 13
 * Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
 * The power of 13 is 9
 * The power of 14 is 17
 * The power of 15 is 17
 * The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
 * Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.
 * Example 2:
 * Input: lo = 1, hi = 1, k = 1
 * Output: 1
 * Example 3:
 * Input: lo = 7, hi = 11, k = 4
 * Output: 7
 * Explanation: The power array corresponding to the interval [7, 8, 9, 10, 11] is [16, 3, 19, 6, 14].
 * The interval sorted by power is [8, 10, 11, 7, 9].
 * The fourth number in the sorted array is 7.
 * Example 4:
 * Input: lo = 10, hi = 20, k = 5
 * Output: 13
 * Example 5:
 * Input: lo = 1, hi = 1000, k = 777
 * Output: 570
 */

/**
 * 按照规则计算step即可，但是如果每一个数都重复计算的话速度会慢，可以用map将计算过的数值保存起来，还有这里求第k个数，原则上建立k个数值的堆排序最好，这里为了实现简单把所有数值保存起来排序。
 */

class Solution {
    public:
        int getKth(int lo, int hi, int k) {
            assert(k >= 1);
            assert(hi - lo >= k - 1);
            const int len = hi - lo + 1;
            vector<ValueStep> steps(len);
            for (int i = 0; i < len; ++i) {
                ValueStep& item = steps[i];
                item.value = lo + i;
                item.step = getStep(item.value);
            }
            std::sort(steps.begin(), steps.end(), [](const ValueStep& l, const ValueStep& r) {
                if (l.step < r.step) {
                    return true;
                } else if (l.step == r.step) {
                    return l.value < r.value;
                } else {
                    return false;
                }
            });
            return steps[k - 1].value;
        }
    private:
        struct ValueStep {
            int value;
            int step;
        };
    private:
        int getStep(int x) {
            auto iter = cache.find(x);
            if (iter != cache.end()) {
                return iter->second;
            }
            int value;
            if (x == 1) {
                value = 1;
            } else if (x % 2 == 0) {
                value = 1 + getStep(x / 2);
            } else {
                value = 1 + getStep(3 * x + 1);
            }
            cache[x] = value;
            return value;
        }
    private:
        std::unordered_map<int, int> cache;
};
