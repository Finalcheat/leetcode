/**
 * @file My-Calendar-I.cpp
 * @brief 我的日历(https://leetcode.com/problems/my-calendar-i/description/)
 * @author Finalcheat
 * @date 2018-07-31
 */

/**
 * Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.
 * Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.
 * A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)
 * For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 * Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
 * Example 1:
 * MyCalendar();
 * MyCalendar.book(10, 20); // returns true
 * MyCalendar.book(15, 25); // returns false
 * MyCalendar.book(20, 30); // returns true
 * Explanation:
 * The first event can be booked.  The second can't because time 15 is already booked by another event.
 * The third event can be booked, as the first event takes every time less than 20, but not including 20.
 */

/**
 * 线段树是最符合要求的方法，但是这里简单实现线性查询即可。
 */


class MyCalendar {
    public:
        MyCalendar() {
        }
        bool book(int start, int end) {
            for (size_t i = 0; i < v.size(); ++i) {
                const std::pair<int, int>& p = v[i];
                if (start < p.second && end > p.first) {
                    return false;
                }
            }
            v.push_back(std::make_pair(start, end));
            return true;
        }
    private:
        std::vector< std::pair<int, int> > v;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
