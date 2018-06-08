/**
 * @file Roman-to-Integer.cpp
 * @brief 罗马数字转阿拉伯数字(https://leetcode.com/problems/roman-to-integer/)
 * @author Finalcheat
 * @date 2016-04-08
 */

/**
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

/**
 * 首先参考[罗马数字](https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97)的定义，遍历字符串，比较前后字符转换成阿拉伯数字的大小进行不同计算即可。
 */

class Solution {
    public:
        int romanToInt(string s) {
            if (s.empty()) {
                return 0;
            }
            int sum = charToInt(s[0]);
            int prev = sum;
            for (size_t i = 1; i < s.size(); ++i) {
                int current = charToInt(s[i]);
                if (current <= prev) {
                    sum += current;
                } else {
                    sum = sum - prev * 2 + current;
                }
                prev = current;
            }
            return sum;
        }
        
    private:
        int charToInt(char c) {
            int val = 0;
            switch (c) {
                case 'I':
                    val = 1;
                    break;
                case 'V':  
                    val = 5;  
                    break;  
                case 'X':  
                    val = 10;  
                    break;  
                case 'L':  
                    val = 50;  
                    break;  
                case 'C':  
                    val = 100;  
                    break;  
                case 'D':  
                    val = 500;  
                    break;  
                case 'M':  
                    val = 1000;  
                    break;  
            }
            return val;
        }
};
