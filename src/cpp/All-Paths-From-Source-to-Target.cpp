/**
 * @file All-Paths-From-Source-to-Target.cpp
 * @brief 所有可能的路径(https://leetcode.com/problems/all-paths-from-source-to-target/description/)
 * @author Finalcheat
 * @date 2018-09-17
 */

/**
 * Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
 * The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
 * Example:
 * Input: [[1,2], [3], [3], []]
 * Output: [[0,1,3],[0,2,3]]
 * Explanation: The graph looks like this:
 * 0--->1
 * |    |
 * v    v
 * 2--->3
 * There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 */

/**
 * 深度优先搜索即可。
 */


class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            vector< vector<int> > result;
            vector<int> path;
            _allPathsSourceTarget(graph, result, path, 0);
            return result;
        }
    private:
        void _allPathsSourceTarget(const vector< vector<int> >& graph, vector< vector<int> >& result,
                                vector<int> path, const int idx) {
            path.push_back(idx);
            if (idx == graph.size() - 1) {
                result.push_back(path);
                return;
            }
            for (size_t i = 0; i < graph[idx].size(); ++i) {
                _allPathsSourceTarget(graph, result, path, graph[idx][i]);
            }
        }
};
