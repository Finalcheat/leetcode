/**
 * @file Find-Eventual-Safe-States.cpp
 * @brief 找到最终的安全状态(https://leetcode.com/problems/find-eventual-safe-states/description/)
 * @author Finalcheat
 * @date 2018-09-28
 */

/**
 * In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.
 * Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.
 * Which nodes are eventually safe?  Return them as an array in sorted order.
 * The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.
 * Example:
 * Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output: [2,4,5,6]
 */

/**
 * dfs搜索，这里用hashtable存储已经计算过的结果。
 */


class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            vector<int> result;
            vector<int> visited(graph.size(), 0);
            for (int i = 0; i < graph.size(); ++i) {
                if (dfs(graph, i, visited)) {
                    result.push_back(i);
                }
            }
            return result;
        }
    private:
        bool dfs(const vector< vector<int> >& graph, const int idx, vector<int>& visited) {
            const auto iter = u.find(idx);
            if (iter != u.end()) {
                return iter->second;
            }
            if (visited[idx]) {
                u[idx] = false;
                return false;
            }
            visited[idx] = 1;
            for (const int i : graph[idx]) {
                if (!dfs(graph, i, visited)) {
                    return false;
                }
                visited[i] = 0;
            }
            visited[idx] = 0;
            u[idx] = true;
            return true;
        }
    private:
        std::unordered_map<int, bool> u;
};
