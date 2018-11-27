/**
 * @file Peeking-Iterator.cpp
 * @brief 顶端迭代器(https://leetcode.com/problems/peeking-iterator/description/)
 * @author Finalcheat
 * @date 2018-10-27
 */

/**
 * Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().
 * Example:
 * Assume that the iterator is initialized to the beginning of the list: [1,2,3].
 * Call next() gets you 1, the first element in the list.
 * Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
 * You call next() the final time and it returns 3, the last element.
 * Calling hasNext() after that should return false.
 */

/**
 * 用一个变量flag做标记并且用val记录peek的值。
 */


// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
        Data* data;
    public:
        Iterator(const vector<int>& nums);
        Iterator(const Iterator& iter);
        virtual ~Iterator();
        // Returns the next element in the iteration.
        int next();
        // Returns true if the iteration has more elements.
        bool hasNext() const;
};


class PeekingIterator : public Iterator {
    public:
        PeekingIterator(const vector<int>& nums) : flag(false), Iterator(nums) {
            // Initialize any member here.
            // **DO NOT** save a copy of nums and manipulate it directly.
            // You should only use the Iterator interface methods.
        }

            // Returns the next element in the iteration without advancing the iterator.
        int peek() {
                if (!flag) {
                    val = Iterator::next();
                    flag = true;
                }
                return val;
        }

        // hasNext() and next() should behave the same as in the Iterator interface.
        // Override them if needed.
        int next() {
            if (flag) {
                    flag = false;
                    return val;
                }
                return Iterator::next();
        }

        bool hasNext() const {
            if (flag) {
                    return true;
                }
                return Iterator::hasNext();
        }
    private:
        bool flag;
        int val;
};
