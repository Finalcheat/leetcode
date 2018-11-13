/**
 * @file Loud-and-Rich.cpp
 * @brief 喧闹和富有(https://leetcode.com/problems/loud-and-rich/description/)
 * @author Finalcheat
 * @date 2018-11-07
 */

/**
 * In a group of N people (labelled 0, 1, 2, ..., N-1), each person has different amounts of money, and different levels of quietness.
 * For convenience, we'll call the person with label x, simply "person x".
 * We'll say that richer[i] = [x, y] if person x definitely has more money than person y.  Note that richer may only be a subset of valid observations.
 * Also, we'll say quiet[x] = q if person x has quietness q.
 * Now, return answer, where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]), among all people who definitely have equal to or more money than person x.
 * Example 1:
 * Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
 * Output: [5,5,2,5,4,5,6,7]
 * Explanation:
 * answer[0] = 5.
 * Person 5 has more money than 3, which has more money than 1, which has more money than 0.
 * The only person who is quieter (has lower quiet[x]) is person 7, but
 * it isn't clear if they have more money than person 0.
 * answer[7] = 7.
 * Among all people that definitely have equal to or more money than person 7
 * (which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x]) is person 7.
 * The other answers can be filled out with similar reasoning.
 */

/**
 * 深度优先搜索即可，注意搜索过程中记录已经计算出结果的值避免重复计算。
 */


class Solution {
    public:
        vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
            std::unordered_map<int, std::vector<int> > u;
            for (const std::vector<int>& v : richer) {
                assert(v.size() >= 2);
                const int personX = v[0];
                const int personY = v[1];
                auto iter = u.find(personY);
                if (iter == u.end()) {
                    std::vector<int> persons{personX};
                    u[personY] = persons;
                } else {
                    std::vector<int>& persons = iter->second;
                    persons.push_back(personX);
                }
            }
            std::vector<int> answer(quiet.size(), -1);
            for (int i = 0; i < answer.size(); ++i) {
                _dfs(i, u, quiet, answer);
            }
            return answer;
        }

    private:
        int _dfs(const int x, const std::unordered_map<int, std::vector<int> >& u,
                const std::vector<int>& quiet, std::vector<int>& answer) {
            if (answer[x] == -1) {
                answer[x] = x;
                const auto iter = u.find(x);
                if (iter == u.end()) {
                    return answer[x];
                }
                const std::vector<int>& persons = iter->second;
                for (const int person : persons) {
                    const int _x = _dfs(person, u, quiet, answer);
                    if (quiet[_x] < quiet[answer[x]]) {
                        answer[x] = _x;
                    }
                }
            }
            return answer[x];
        }
};
