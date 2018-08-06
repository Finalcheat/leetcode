/**
 * @file Lemonade-Change.cpp
 * @brief  Lemonade Change(https://leetcode.com/problems/lemonade-change/description/)
 * @author Finalcheat
 * @date 2018-07-25
 */

/**
 * At a lemonade stand, each lemonade costs $5.
 * Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).
 * Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.
 * Note that you don't have any change in hand at first.
 * Return true if and only if you can provide every customer with correct change.
 * Example 1:
 * Input: [5,5,5,10,20]
 * Output: true
 * Explanation:
 * From the first 3 customers, we collect three $5 bills in order.
 * From the fourth customer, we collect a $10 bill and give back a $5.
 * From the fifth customer, we give a $10 bill and a $5 bill.
 * Since all customers got correct change, we output true.
 * Example 2:
 * Input: [5,5,10]
 * Output: true
 * Example 3:
 * Input: [10,10]
 * Output: false
 * Example 4:
 * Input: [5,5,10,10,20]
 * Output: false
 * Explanation:
 * From the first two customers in order, we collect two $5 bills.
 * For the next two customers in order, we collect a $10 bill and give back a $5 bill.
 * For the last customer, we can't give change of $15 back because we only have two $10 bills.
 * Since not every customer received correct change, the answer is false.
 */

/**
 * 贪心算法，优先找10，最后找5。
 */


class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            std::unordered_map<int, int> u;
            for (size_t i = 0; i < bills.size(); ++i) {
                int bill = bills[i];
                if (bill == 5) {
                    ++u[bill];
                } else if (bill == 10) {
                    auto iter = u.find(5);
                    if (iter == u.end()) {
                        return false;
                    }
                    if (iter->second <= 0) {
                        return false;
                    }
                    --(iter->second);
                    ++u[10];
                } else {
                    int count = 15;
                    auto iter10 = u.find(10);
                    if (iter10 != u.end() && iter10->second > 0) {
                        count -= 10;
                        --(iter10->second);
                    }
                    auto iter5 = u.find(5);
                    if (iter5 == u.end()) {
                        return false;
                    }
                    int c5 = count / 5;
                    if (iter5->second < c5) {
                        return false;
                    }
                    iter5->second = iter5->second - c5;
                    ++u[20];
                }
            }
            return true;
        }
};
