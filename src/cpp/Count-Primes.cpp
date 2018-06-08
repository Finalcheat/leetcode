/**
 * @file Count-Primes.cpp
 * @brief 素数的个数(https://leetcode.com/problems/count-primes/) 
 * @author Finalcheat
 * @date 2016-05-17
 */

/**
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 */

/**
 * [看图](http://7xl4we.com1.z0.glb.clouddn.com/Sieve_of_Eratosthenes_animation.gif)
 */

class Solution {
    public:
        int countPrimes(int n) {
            std::vector<bool> isPrime(n);
            for (int i = 2; i < n; ++i) {
                isPrime[i] = true;
            }
            for (int i = 2; i * i < n; ++i) {
                if (!isPrime[i]) {
                    continue;
                }
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
            int count = 0;
            for (int i = 2; i < n; i++) {
                if (isPrime[i]) {
                    ++count;
                }
            }
            return count;
        }
};
