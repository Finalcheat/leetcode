/**
 * @file Prime-Number-of-Set-Bits-in-Binary-Representation.cpp
 * @brief 二进制表示中设置位的素数(https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/)
 * @author Finalcheat
 * @date 2018-04-05
 */

/**
 * Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.
 * (Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)
 * Example 1:
 * Input: L = 6, R = 10
 * Output: 4
 * Explanation:
 * 6 -> 110 (2 set bits, 2 is prime)
 * 7 -> 111 (3 set bits, 3 is prime)
 * 9 -> 1001 (2 set bits , 2 is prime)
 * 10->1010 (2 set bits , 2 is prime)
 * Example 2:
 * Input: L = 10, R = 15
 * Output: 5
 * Explanation:
 * 10 -> 1010 (2 set bits, 2 is prime)
 * 11 -> 1011 (3 set bits, 3 is prime)
 * 12 -> 1100 (2 set bits, 2 is prime)
 * 13 -> 1101 (3 set bits, 3 is prime)
 * 14 -> 1110 (3 set bits, 3 is prime)
 * 15 -> 1111 (4 set bits, 4 is not prime)
 */

/**
 * 循环遍历过程计算出二进制表示1的个数，然后判断是否是素数，最后统计总数即可。
 */


class Solution {

    public:
        int countPrimeSetBits(int L, int R) {
            int count = 0;
            for (; L <= R; ++L) {
                const int num = oneCount(L);
                if (isPrime(num)) {
                    ++count;
                }
            }
            return count;
        }

    private:
        int oneCount(int num) {
            int count = 0;
            while (num != 0) {
                count += (num & 1);
                num >>= 1;
            }
            return count;
        }

        bool isPrime(int num) {
            const int n = static_cast<int>(std::sqrt(num));
            for (int i = 2; i <= n; ++i) {
                if (num % i == 0) {
                    return false;
                }
            }
            return (num != 1);
        }

};
