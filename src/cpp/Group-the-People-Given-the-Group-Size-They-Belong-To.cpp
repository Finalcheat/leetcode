/**
 * @file Group-the-People-Given-the-Group-Size-They-Belong-To.cpp
 * @brief 根据所属的群体大小来分组(https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)
 * @author Finalcheat
 * @date 2020-05-07
 */

/**
 * There are n people whose IDs go from 0 to n - 1 and each person belongs exactly to one group. Given the array groupSizes of length n telling the group size each person belongs to, return the groups there are and the people's IDs each group includes.
 * You can return any solution in any order and the same applies for IDs. Also, it is guaranteed that there exists at least one solution. 
 * Example 1:
 * Input: groupSizes = [3,3,3,3,3,1,3]
 * Output: [[5],[0,1,2],[3,4,6]]
 * Explanation:
 * Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
 * Example 2:
 * Input: groupSizes = [2,1,3,3,3,2]
 * Output: [[1],[0,5],[2,3,4]]
 * Constraints:
 * * groupSizes.length == n
 * * 1 <= n <= 500
 * * 1 <= groupSizes[i] <= n
 */

/**
 * 用map根据次数来分组即可。
 */

class Solution {
    public:
        vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
            std::unordered_map<int, vector<int>> u;
            vector<vector<int>> result;
            for (int i = 0; i < groupSizes.size(); ++i) {
                vector<int>& v = u[groupSizes[i]];
                v.push_back(i);
                if (v.size() == groupSizes[i]) {
                    result.push_back(v);
                    v.clear();
                }
            }
            return result;
        }
};
