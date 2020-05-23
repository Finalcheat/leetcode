/**
 * @file Destination-City.cpp
 * @brief 目的城市(https://leetcode.com/problems/destination-city/)
 * @author Finalcheat
 * @date 2020-05-23
 */

/**
 * You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.
 * It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
 * Example 1:
 * Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
 * Output: "Sao Paulo" 
 * Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
 * Example 2:
 * Input: paths = [["B","C"],["D","B"],["C","A"]]
 * Output: "A"
 * Explanation: All possible trips are: 
 * "D" -> "B" -> "C" -> "A". 
 * "B" -> "C" -> "A". 
 * "C" -> "A". 
 * "A". 
 * Clearly the destination city is "A".
 * Example 3:
 * Input: paths = [["A","Z"]]
 * Output: "Z"
 * Constraints:
 * * 1 <= paths.length <= 100
 * * paths[i].length == 2
 * * 1 <= cityAi.length, cityBi.length <= 10
 * * cityAi != cityBi
 * * All strings consist of lowercase and uppercase English letters and the space character.
 */

/**
 * 用map记录path路径，最后遍历找到没有出路的就是目的城市。
 */

class Solution {
    public:
        string destCity(vector<vector<string>>& paths) {
            std::unordered_map<string, string> cityMap;
            for (const vector<string>& path : paths) {
                assert(path.size() == 2);
                const string& src = path[0];
                const string& dst = path[1];
                cityMap[src] = dst;
            }
            std::unordered_map<string, string>::const_iterator iter = cityMap.begin();
            string dst = "";
            while (iter != cityMap.end()) {
                dst = iter->second;
                iter = cityMap.find(dst);
            }
            return dst;
        }
};
