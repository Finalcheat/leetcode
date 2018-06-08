/**
 * @file Subdomain-Visit-Count.cpp
 * @brief 子域名访问次数(https://leetcode.com/problems/subdomain-visit-count/description/)
 * @author Finalcheat
 * @date 2018-04-02
 */

/**
 * A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
 * Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".
 * We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.
 * Example 1:
 * Input:
 * ["9001 discuss.leetcode.com"]
 * Output:
 * ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
 * Explanation:
 * We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.
 * Example 2:
 * Input:
 * ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
 * Output:
 * ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
 * Explanation:
 * We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.
 */

/**
 * 用hashtable记录字符串出现的次数就行了，其余的问题就是分割字符串而已。
 */


class Solution {
    public:
        vector<string> subdomainVisits(vector<string>& cpdomains) {
            std::map<string, size_t> m;
            std::vector<string> result;
            for (size_t i = 0; i < cpdomains.size(); ++i) {
                const string& cpdomain = cpdomains[i];
                const std::size_t spaceIdx = cpdomain.find_first_of(' ');
                if (spaceIdx == std::string::npos) {
                    continue;
                }
                const string visitStr = cpdomain.substr(0, spaceIdx);
                const size_t visitNum = std::stoi(visitStr);
                std::size_t dotIdx = spaceIdx;
                std::size_t lastIdx;
                do {
                    lastIdx = dotIdx + 1;
                    dotIdx = cpdomain.find_first_of('.', lastIdx);
                    const string s = cpdomain.substr(lastIdx, cpdomain.size() - lastIdx);
                    auto iter = m.find(s);
                    if (iter != m.end()) {
                        iter->second += visitNum;
                    } else {
                        m[s] = visitNum;
                    }
                } while (dotIdx != std::string::npos);
            }
            for (const auto pair : m) {
                result.push_back(std::to_string(pair.second) + " " + pair.first);
            }
            return result;
        }
};
