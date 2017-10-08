/**
 * @file Judge-Route-Circle.cpp
 * @brief 判断环路(https://leetcode.com/problems/judge-route-circle/)
 * @author Finalcheat
 * @date 2017-10-08
 */

/**
 * Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
 * The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
 * Example 1:
 * Input: "UD"
 * Output: true
 * Example 2:
 * Input: "LL"
 * Output: false
 */

/**
 * 很简单的题目，水平方向和垂直方向各自一个变量标识即可，向上移动垂直方向变量+1，向下-1，最后水平方向和垂直方向为0即为环路。
 */

class Solution {
    public:
        bool judgeCircle(string moves) {
            int horizontal = 0;
            int vertical = 0;
            for (size_t i = 0; i < moves.size(); ++i) {
                if (moves[i] == 'R') {
                    ++horizontal;
                } else if (moves[i] == 'L') {
                    --horizontal;
                } else if (moves[i] == 'U') {
                    ++vertical;
                } else {
                    --vertical;
                }
            }
            if (horizontal == 0 && vertical == 0) {
                return true;
            }
            return false;
        }
};
