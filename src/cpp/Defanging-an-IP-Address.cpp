/**
 * @file Defanging-an-IP-Address.cpp
 * @brief Defanging an IP Address(https://leetcode.com/problems/defanging-an-ip-address/)
 * @author Finalcheat
 * @date 2020-03-02
 */

/**
 * Given a valid (IPv4) IP address, return a defanged version of that IP address.
 * A defanged IP address replaces every period "." with "[.]".
 * Example 1:
 * Input: address = "1.1.1.1"
 * Output: "1[.]1[.]1[.]1"
 * Example 2:
 * Input: address = "255.100.50.0"
 * Output: "255[.]100[.]50[.]0"
 */

/**
 * 送分题，就是简单的替换。
 */

class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for (char c : address) {
            if (c == '.') {
                result += "[.]";
            } else {
                result += c;
            }
        }
        return result;
    }
};
