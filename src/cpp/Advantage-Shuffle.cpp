/**
 * @file Advantage-Shuffle.cpp
 * @brief 洗牌优势(https://leetcode.com/problems/advantage-shuffle/description/)
 * @author Finalcheat
 * @date 2018-09-29
 */

/**
 * Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
 * Return any permutation of A that maximizes its advantage with respect to B.
 * Example 1:
 * Input: A = [2,7,11,15], B = [1,10,4,11]
 * Output: [2,11,7,15]
 * Example 2:
 * Input: A = [12,24,8,32], B = [13,25,32,11]
 * Output: [24,32,8,12]
 */

/**
 * 田忌赛马，首先用hashtable记录A各数字出现次数，然后遍历B在A中寻找比B刚好大的元素填充上去。
 */


class Solution {
    public:
        vector<int> advantageCount(vector<int>& A, vector<int>& B) {
            assert(A.size() == B.size());
            std::map<int, int> am;
            for (int i = 0; i < A.size(); ++i) {
                const int num = A[i];
                ++am[num];
            }
            for (size_t i = 0; i < B.size(); ++i) {
                const int num = B[i];
                auto iter = am.upper_bound(num);
                if (iter == am.end()) {
                    iter = am.begin();
                    A[i] = iter->first;
                }
                A[i] = iter->first;
                if (--iter->second == 0) {
                    am.erase(iter);
                }
            }
            return A;
        }
};
