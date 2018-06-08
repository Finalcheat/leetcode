/**
 * @file Counting-Bits.cpp
 * @brief 计算数字bit表示1的个数(https://leetcode.com/problems/counting-bits/) 
 * @author Finalcheat
 * @date 2016-03-29
 */


/**
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
 * Example:
 * For num = 5 you should return [0,1,1,2,1,2].
 * Follow up:
 * - It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
 * - Space complexity should be O(n).
 * - Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 */

/**
 * 一个数是2的整数幂，1的个数是1，比如1(01)、2(10)、4(100)、8(1000)。
 * 不是2的整数幂，1的个数等于它的前一个序列的数+1。
 */

class Solution {
    public:
        vector<int> countBits(int num) {
            vector<int> bits(num + 1, 0);
            int pow = 1;
            int before = 1;
            for (int i = 1; i <= num; ++i) {
                if (i == pow) {
                    before = bits[i] = 1;
                    pow <<= 1;
                } else {
                    bits[i] = bits[before] + 1;
                    before += 1;
                }
            }
            return bits;
        }
};
