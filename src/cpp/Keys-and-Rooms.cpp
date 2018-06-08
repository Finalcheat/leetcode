/**
 * @file Keys-and-Rooms.cpp
 * @brief Keys and Rooms(https://leetcode.com/problems/keys-and-rooms/description/)
 * @author Finalcheat
 * @date 2018-05-31
 */

/**
 * There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 
 * Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.
 * Initially, all the rooms start locked (except for room 0).
 * You can walk back and forth between rooms freely.
 * Return true if and only if you can enter every room.
 * Example 1:
 * Input: [[1],[2],[3],[]]
 * Output: true
 * Explanation:
 * We start in room 0, and pick up key 1.
 * We then go to room 1, and pick up key 2.
 * We then go to room 2, and pick up key 3.
 * We then go to room 3.  Since we were able to go to every room, we return true.
 * Example 2:
 * Input: [[1,3],[3,0,1],[2],[0]]
 * Output: false
 * Explanation: We can't enter the room with number 2.
 */


/**
 * 使用栈作为辅助结构，将idx位置中的所有元素push到栈中，同时记录idx位置是否已经被访问，已访问则不push到栈中，最后检查所有位置是否已经设置为已访问即可。
 */


class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            vector<int> v(rooms.size());
            assert(v.size() > 0);
            std::stack<int> s;
            s.push(0);
            while (!s.empty()) {
                const int idx = s.top();
                v[idx] = 1;
                s.pop();
                const vector<int>& room = rooms[idx];
                for (size_t i = 0; i < room.size(); ++i) {
                    if (v[room[i]] == 0) {
                        s.push(room[i]);
                    }
                }
            }
            for (size_t i = 0; i < v.size(); ++i) {
                if (v[i] == 0) {
                    return false;
                }
            }
            return true;
        }
};
