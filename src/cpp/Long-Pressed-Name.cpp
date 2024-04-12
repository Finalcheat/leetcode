/**
 * @file Long-Pressed-Name.cpp
 * @brief 长按键入(https://leetcode.com/problems/long-pressed-name)
 * @author Finalcheat
 * @date 2018-12-03
 * @update 2024-04-12
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
 * 双指针，比较当前双指针字符，不想等直接返回false，否则双指针继续前进，前进过程中统计重复出现的字符个数，name的个数必须小于等于typed的个数，否则返回false，最后判断双指针是否同时走到字符串终点。
 */


class Solution {
    public:
        bool isLongPressedName(string name, string typed) {
            int nameIdx = 0;
            int typedIdx = 0;
            while (nameIdx < name.size() && typedIdx < typed.size()) {
                if (name[nameIdx] != typed[typedIdx]) {
                    return false;
                }
                ++nameIdx;
                ++typedIdx;
                int nameCnt = 1;
                while (nameIdx < name.size() && name[nameIdx] == name[nameIdx - 1]) {
                    ++nameIdx;
                    ++nameCnt;
                }
                int typedCnt = 1;
                while (typedIdx < typed.size() && typed[typedIdx] == typed[typedIdx - 1]) {
                    ++typedIdx;
                    ++typedCnt;
                }
                if (nameCnt > typedCnt) {
                    return false;
                }
            }
            return nameIdx == name.size() && typedIdx == typed.size();
        }
};
