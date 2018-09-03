/**
 * @file 1-bit-and-2-bit-Characters.cpp
 * @brief 1比特与2比特字符(https://leetcode.com/problems/1-bit-and-2-bit-characters/description/)
 * @author Finalcheat
 * @date 2018-08-29
 */

/**
 * We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).
 * Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.
 * Example 1:
 * Input:
 * bits = [1, 0, 0]
 * Output: True
 * Explanation:
 * The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
 * Example 2:
 * Input:
 * bits = [1, 1, 1, 0]
 * Output: False
 * Explanation:
 * The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
 */

/**
 * 因为有特殊性，遇到1直接位置+2，遇到0直接位置+1，最后判断是否超出界限和为0即可。
 */


class Solution {
    public:
        bool isOneBitCharacter(vector<int>& bits) {
            return _isOneBitCharacter(bits, 0);
        }
    private:
        bool _isOneBitCharacter(const vector<int>& bits, size_t idx) {
            if (idx >= bits.size()) {
                return false;
            }
            int bit = bits[idx];
            if (bit == 1) {
                return _isOneBitCharacter(bits, idx + 2);
            } else {
                return (idx + 1 == bits.size()) ? true : _isOneBitCharacter(bits, idx + 1);
            }
        }
};
