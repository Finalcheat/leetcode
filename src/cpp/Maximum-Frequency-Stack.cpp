/**
 * @file Maximum-Frequency-Stack.cpp
 * @brief 最大频率栈(https://leetcode.com/problems/maximum-frequency-stack/description/)
 * @author Finalcheat
 * @date 2018-10-08
 */

/**
 * Implement FreqStack, a class which simulates the operation of a stack-like data structure.
 * FreqStack has two functions:
 * * push(int x), which pushes an integer x onto the stack.
 * * pop(), which removes and returns the most frequent element in the stack.
 * * * If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 * Example 1:
 * Input:
 * ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
 * [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
 * Output: [null,null,null,null,null,null,null,5,7,5,4]
 * Explanation:
 * After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:
 * pop() -> returns 5, as 5 is the most frequent.
 * The stack becomes [5,7,5,7,4].
 * pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
 * The stack becomes [5,7,5,4].
 * pop() -> returns 5.
 * The stack becomes [5,7,4].
 * pop() -> returns 4.
 * The stack becomes [5,7].
 */

/**
 * 用hashtable建立数字以及出现次数的对应关系，再用另外一个hashtable记录出现次数以及stack的对应关系。
 */


class FreqStack {
public:
    FreqStack() : maxFreq(0) {
    }

    void push(int x) {
        int count = ++numTimesMap[x];
        timesStackMap[count].push(x);
        if (count > maxFreq) {
            maxFreq = count;
        }
    }

    int pop() {
        auto iter = timesStackMap.find(maxFreq);
        assert(iter != timesStackMap.end());
        std::stack<int>& s = iter->second;
        const int x = s.top();
        if (--numTimesMap[x] <= 0) {
            numTimesMap.erase(x);
        }
        s.pop();
        if (s.empty()) {
            --maxFreq;
            timesStackMap.erase(iter);
        }
        return x;
    }
private:
    int maxFreq;
    std::unordered_map<int, int> numTimesMap;
    std::unordered_map<int, std::stack<int> > timesStackMap;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
