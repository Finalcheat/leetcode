/**
 * @file Compare-Version-Numbers.cpp
 * @brief 版本号比较(https://leetcode.com/problems/compare-version-numbers/) 
 * @author Finalcheat
 * @date 2016-05-18
 */

/**
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 * Here is an example of version numbers ordering:
 * 0.1 < 1.1 < 1.2 < 13.37
 */

/**
 * 将字符串按.分割然后转成int比较即可，比较简单。
 */

class Solution {
    public:
        int compareVersion(string version1, string version2) {
            std::vector<std::string> v1 = split(version1, '.');
            std::vector<std::string> v2 = split(version2, '.');
            size_t maxLen = std::max(v1.size(), v2.size());
            for (size_t i = 0; i < maxLen; ++i) {
                int value1 = i < v1.size() ? std::stoi(v1[i]) : 0;
                int value2 = i < v2.size() ? std::stoi(v2[i]) : 0;
                if (value1 > value2) {
                    return 1;
                } else if (value1 < value2) {
                    return -1;
                }
            }
            return 0;
        }
        
    private:
        std::vector<std::string> split(const std::string &s, char delim) {
            std::stringstream ss(s);
            std::string item;
            std::vector<std::string> elems;
            while (std::getline(ss, item, delim)) {
                elems.push_back(std::move(item));
            }
            return elems;
        }
};
