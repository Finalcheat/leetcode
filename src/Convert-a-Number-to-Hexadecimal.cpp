/**
 * @file Convert-a-Number-to-Hexadecimal.cpp
 * @brief 数字转成16进制字符串(https://leetcode.com/problems/convert-a-number-to-hexadecimal/)
 * @author Finalcheat
 * @date 2017-03-19
 */

/**
 * Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
 * Note:
 * 1. All letters in hexadecimal (a-f) must be in lowercase.
 * 2. The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
 * 3. The given number is guaranteed to fit within the range of a 32-bit signed integer.
 * 4. You must not use any method provided by the library which converts/formats the number to hex directly.
 * Example 1:
 * Input:
 * 26
 * Output:
 * "1a"
 * Example 2:
 * Input:
 * -1
 *  Output:
 *  "ffffffff"
 */

/**
 * 按照进制转换的方法即可，注意负数和0的情况。
 */

class Solution {
    public:
        string toHex(int num) {
            if (num == 0) {
                return "0";
            }
            unsigned int _num = num;
            std::stack<int> s;
            while (_num) {
                s.push(_num % 16);
                _num = _num / 16;
            }
            string result;
            while (!s.empty()) {
                int n = s.top();
                s.pop();
                char c;
                switch (n) {
                    case 10:
                        c = 'a';
                        break;
                    case 11:
                        c = 'b';
                        break;
                    case 12:
                        c = 'c';
                        break;
                    case 13:
                        c = 'd';
                        break;
                    case 14:
                        c = 'e';
                        break;
                    case 15:
                        c = 'f';
                        break;
                    default:
                        c = '0' + n;
                        break;
                }
                result += c;
            }
            return result;
        }
};
