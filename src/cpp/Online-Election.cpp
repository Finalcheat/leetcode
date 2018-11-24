/**
 * @file Online-Election.cpp
 * @brief 在线选举(https://leetcode.com/problems/online-election/description/)
 * @author Finalcheat
 * @date 2018-11-06
 */

/**
 * In an election, the i-th vote was cast for persons[i] at time times[i].
 * Now, we would like to implement the following query function: TopVotedCandidate.q(int t) will return the number of the person that was leading the election at time t.
 * Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.
 * Example 1:
 * Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
 * Output: [null,0,1,1,0,0,1]
 * Explanation:
 * At time 3, the votes are [0], and 0 is leading.
 * At time 12, the votes are [0,1,1], and 1 is leading.
 * At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
 * This continues for 3 more queries at time 15, 24, and 8.
 */

/**
 * 用map记录某时刻对应的选举结果即可。
 */


class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        assert(persons.size() == times.size());
        std::unordered_map<int, int> u;
        int maximum = 0;
        int maximumPerson = -1;
        for (size_t i = 0; i < times.size(); ++i) {
            const int person = persons[i];
            const int count = ++u[person];
            if (count >= maximum) {
                maximum = count;
                maximumPerson = person;
            }
            m[times[i]] = maximumPerson;
        }
    }

    int q(int t) {
        auto iter = m.lower_bound(t);
        if (iter != m.end()) {
            if (iter->first == t) {
                return iter->second;
            }
            --iter;
            return iter->second;
        }
        auto rIter = m.rbegin();
        if (rIter == m.rend()) {
            return -1;
        }
        return rIter->second;
    }

private:
    std::map<int, int> m;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
