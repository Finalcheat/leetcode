/**
 * @file Top-K-Frequent-Words.cpp
 * @brief 前k个频繁出现的单词(https://leetcode.com/problems/top-k-frequent-words/description/)
 * @author Finalcheat
 * @date 2018-03-24
 */

/**
 * Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
 * Example 1:
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * Note that "i" comes before "love" due to a lower alphabetical order.
 * Example 2:
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
 * with the number of occurrence being 4, 3, 2 and 1 respectively.
 */

/**
 * 首先排序，相同的单词则会紧挨着，然后遍历过程中得出出现次数，同时使用最大堆维护前k个出现次数最多的单词。
 */


struct StringInfo {
    StringInfo(const vector<string>::iterator& s, const size_t count) : _s(s), _count(count) {}
    vector<string>::iterator _s;
    size_t _count;
};

bool SolutionCmp(const StringInfo &a, const StringInfo &b) {
    if (a._count == b._count) {
        return *(a._s) < *(b._s);
    }
    return a._count > b._count;
}

class Solution {
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            std::sort(words.begin(), words.end());
            std::vector<string> result;
            auto iter = words.begin();
            if (iter == words.end()) {
                return result;
            }
            size_t count = 1;
            std::vector<StringInfo> heap;
            for (auto next = iter + 1; next != words.end(); iter = next, ++next) {
                if (*iter == *next) {
                    ++count;
                } else {
                    if (heap.size() < k) {
                        heap.push_back(StringInfo(iter, count));
                        std::push_heap(heap.begin(), heap.end(), SolutionCmp);
                    } else if (count > heap[0]._count) {
                        heap[0] = StringInfo(iter, count);
                        std::make_heap(heap.begin(), heap.end(), SolutionCmp);
                    }
                    count = 1;
                }
            }
            if (heap.size() < k) {
                heap.push_back(StringInfo(iter, count));
                std::push_heap(heap.begin(), heap.end(), SolutionCmp);
            } else if (count > heap[0]._count) {
                heap[0] = StringInfo(iter, count);
                std::make_heap(heap.begin(), heap.end(), SolutionCmp);
            }
            while (heap.size() > 0) {
                pop_heap(heap.begin(), heap.end(), SolutionCmp);
                result.push_back(*(heap[heap.size() - 1]._s));
                // result.push_back(*(heap[heap.size() - 1]._s) + "_" + std::to_string(heap[heap.size() - 1]._count));
                heap.pop_back();
            }
            std::reverse(result.begin(), result.end());
            return result;
        }
};
