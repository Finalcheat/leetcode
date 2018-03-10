/**
 * @file Jewels-and-Stones.cpp
 * @brief 珠宝和石头(https://leetcode.com/problems/jewels-and-stones/description/)
 * @author Finalcheat
 * @date 2018-03-10
 */

/**
 * You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.
 * The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
 * Example 1:
 * Input: J = "aA", S = "aAAbbbb"
 * Output: 3
 * Example 2:
 * Input: J = "z", S = "ZZ"
 * Output: 0
 */

/**
 * 用hashtable记录S中各个字符出现的次数，然后遍历J搜寻即可。
 */


class Solution {
    public:
        int numJewelsInStones(string J, string S) {
            std::unordered_map<char, int> u;
            for (size_t i = 0; i < S.size(); ++i) {
                ++u[S[i]];
            }
            int count = 0;
            for (size_t i = 0; i < J.size(); ++i) {
                auto iter = u.find(J[i]);
                if (iter != u.end()) {
                    count += iter->second;
                }
            }
            return count;
        }
};
