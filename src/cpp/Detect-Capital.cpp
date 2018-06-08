/**
 * @file Detect-Capital.cpp
 * @brief 探测字符串是否表示首都(https://leetcode.com/problems/next-greater-element-i/)
 * @author Finalcheat
 * @date 2017-02-21
 */

/**
 * Given a word, you need to judge whether the usage of capitals in it is right or not.
 * We define the usage of capitals in a word to be right when one of the following cases holds:
 * 1. All letters in this word are capitals, like "USA".
 * 2. All letters in this word are not capitals, like "leetcode".
 * 3. Only the first letter in this word is capital if it has more than one letter, like "Google".
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * Example 1:
 * Input: "USA"
 * Output: True
 * Example 2:
 * Input: "FlaG"
 * Output: False
 * Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
 */

/**
 * 使用状态机的方法判断。
 */

class Solution {

    private:
        enum Status { __s1, __s2, __s3, __s4, __s5 };

    public:
        bool detectCapitalUse(string word) {
            string::const_iterator iter = word.begin();
            Status state = __s1;
            while (iter != word.end()) {
                switch (state) {
                    case __s1:
                        if (*iter >= 'A' && *iter <= 'Z') {
                            state = __s2;
                        } else {
                            state = __s3;
                        }
                        break;
                    case __s2:
                        if (*iter >= 'A' && *iter <= 'Z') {
                            state = __s4;
                        } else {
                            state = __s3;
                        }
                        break;
                    case __s3:
                        if (*iter >= 'A' && *iter <= 'Z') {
                            return false;
                        }
                        break;
                    case __s4:
                        if (*iter >= 'a' && *iter <= 'z') {
                            return false;
                        }
                        break;
                }
                ++iter;
            }
            return true;
        }

};
