/**
 * @file Can-Place-Flowers.cpp
 * @brief 种花问题(https://leetcode.com/problems/can-place-flowers/description/)
 * @author Finalcheat
 * @date 2018-09-18
 */

/**
 * Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 */

/**
 * 判断是否有3个0连着即可。
 */


class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            if (flowerbed.empty()) {
                return false;
            }
            if (flowerbed[0] == 0) {
                flowerbed.insert(flowerbed.begin(), 0);
            }
            if (flowerbed.back() == 0) {
                flowerbed.push_back(0);
            }
            for (size_t i = 2; i < flowerbed.size(); ++i) {
                if (flowerbed[i - 2] == 0 && flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
                    --n;
                    ++i;
                }
                if (n <= 0) {
                    return true;
                }
            }
            return n <= 0;
        }
};
