/**
 * @file Employee-Importance.cpp
 * @brief 员工重要性(https://leetcode.com/problems/employee-importance/description/)
 * @author Finalcheat
 * @date 2018-07-26
 */

/**
 * You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.
 * For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.
 * Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.
 * Example 1:
 * Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
 * Output: 11
 * Explanation:
 * Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
 */

/**
 * 使用hashmap存储员工id以及对应的Employee，然后用深度优先搜索即可。
 */


/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
    public:
        int getImportance(vector<Employee*> employees, int id) {
            std::unordered_map<int, Employee*> u;
            for (size_t i = 0; i < employees.size(); ++i) {
                Employee* e = employees[i];
                u[e->id] = e;
            }
            const int result = _getImportance(u, id);
            return result;
        }
    private:
        int _getImportance(const std::unordered_map<int, Employee*>& u, int id) {
            auto iter = u.find(id);
            if (iter == u.end()) {
                return 0;
            }
            const Employee* e = iter->second;
            int result = e->importance;
            const vector<int>& sub = e->subordinates;
            for (size_t i = 0; i < sub.size(); ++i) {
                const int subId = sub[i];
                result += _getImportance(u, subId);
            }
            return result;
        }
};
