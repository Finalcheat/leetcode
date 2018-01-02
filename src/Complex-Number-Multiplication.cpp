/**
 * @file Complex-Number-Multiplication.cpp
 * @brief 复数乘法(https://leetcode.com/problems/complex-number-multiplication/description/)
 * @author Finalcheat
 * @date 2018-01-02
 */

/**
 * Given two strings representing two complex numbers.
 * You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
 * Example 1:
 * Input: "1+1i", "1+1i"
 * Output: "0+2i"
 * Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
 * Example 2:
 * Input: "1+-1i", "1+-1i"
 * Output: "0+-2i"
 * Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 * Note:
 * 1. The input strings will not have extra blank.
 * 2. The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
 */

/**
 * 复数乘法公式：(a+bi)(c+di) = ac + bci + adi - bd = (ac - bd) + (bc + ad)i
 * 分离出各数字按照公式来计算即可，没什么难度。
 */


class Solution {

    private:
        void splitNumber(const string& s, int& aNum, int& bNum) {
            size_t index = s.find_first_of('+');
            const string aStr = s.substr(0, index);
            const string bStr = s.substr(index + 1, s.size() - index - 1);
            aNum = std::stoi(aStr);
            bNum = std::stoi(bStr);
        }

    public:
        string complexNumberMultiply(string a, string b) {
            // (a+bi)(c+di) = ac + bci + adi - bd = (ac - bd) + (bc + ad)i
            int aNum, bNum, cNum, dNum;
            splitNumber(a, aNum, bNum);
            splitNumber(b, cNum, dNum);
            return std::to_string(aNum * cNum - bNum * dNum) + "+" + std::to_string(bNum * cNum + aNum * dNum) + "i";
        }
};
