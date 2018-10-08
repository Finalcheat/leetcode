/**
 * @file Friend-Circles.cpp
 * @brief 朋友圈(https://leetcode.com/problems/friend-circles/description/)
 * @author Finalcheat
 * @date 2018-09-07
 */

/**
 * There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
 * Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.
 * Example 1:
 * Input:
 * [[1,1,0],
 *  [1,1,0],
 *  [0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
 * The 2nd student himself is in a friend circle. So return 2.
 * Example 2:
 * Input:
 * [[1,1,0],
 *  [1,1,1],
 *  [0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
 * so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
 */

/**
 * 用queue作为辅助结构广度优先搜索出同一朋友圈，并且用visits记录是否已访问，最后累加即可。
 */


class Solution {
    public:
        int findCircleNum(vector<vector<int>>& M) {
            std::queue<int> q;
            std::vector<int> visits(M.size(), 0);
            int result = 0;
            for (int i = 0; i < M.size(); ++i) {
                if (visits[i]) {
                    continue;
                }
                q.push(i);
                while (!q.empty()) {
                    int j = q.front();
                    q.pop();
                    visits[j] = 1;
                    for (int k = 0; k < M.size(); ++k) {
                        if (visits[k] == 0 && M[j][k] == 1) {
                            q.push(k);
                        }
                    }
                }
                ++result;
            }
            return result;
        }
};
