/**
 * @file Long-Pressed-Name.cpp
 * @brief 长按键入(https://leetcode.com/problems/long-pressed-name)
 * @author Finalcheat
 * @date 2018-12-03
 */

/**
 * Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
 * You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.
 * Example 1:
 * Input: name = "alex", typed = "aaleex"
 * Output: true
 * Explanation: 'a' and 'e' in 'alex' were long pressed.
 * Example 2:
 * Input: name = "saeed", typed = "ssaaedd"
 * Output: false
 * Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
 * Example 3:
 * Input: name = "leelee", typed = "lleeelee"
 * Output: true
 * Example 4:
 * Input: name = "laiden", typed = "laiden"
 * Output: true
 * Explanation: It's not necessary to long press any character.
 */

/**
 * 记录字符连续出现次数，最后对比即可。
 */


class Solution {
    public:
        bool isLongPressedName(string name, string typed) {
            if (name.size() > typed.size()) {
                return false;
            }
            if (name.empty()) {
                return false;
            }
            char last = name[0];
            size_t count = 1;
            vector<PressedName> nameVector;
            for (size_t i = 0; i < name.size(); ++i) {
                const char c = name[i];
                if (c == last) {
                    ++count;
                } else {
                    nameVector.push_back(PressedName(last, count));
                    last = c;
                    count = 1;
                }
            }
            nameVector.push_back(PressedName(last, count));

            last = typed[0];
            count = 1;
            vector<PressedName> typedVector;
            for (size_t i = 0; i < typed.size(); ++i) {
                const char c = typed[i];
                if (c == last) {
                    ++count;
                } else {
                    typedVector.push_back(PressedName(last, count));
                    last = c;
                    count = 1;
                }
            }
            typedVector.push_back(PressedName(last, count));

            if (nameVector.size() != typedVector.size()) {
                return false;
            }
            for (size_t i = 0; i < nameVector.size(); ++i) {
                const char nameChar = nameVector[i].c;
                const char typedChar = typedVector[i].c;
                if (nameChar != typedChar) {
                    return false;
                }
                const size_t nameCharCount = nameVector[i].count;
                const size_t typedCharCount = typedVector[i].count;
                if (nameCharCount > typedCharCount) {
                    return false;
                }
            }
            return true;
        }
    private:
        struct PressedName {
            PressedName(const char _c, const size_t _count) : c(_c), count(_count) {}
            char c;
            size_t count;
        };
};
