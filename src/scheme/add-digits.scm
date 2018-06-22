;; 258. 各位相加
;; https://leetcode-cn.com/problems/add-digits/description/

;; 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。

;; 示例:
;; 输入: 38
;; 输出: 2
;; 解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。


;; Guile

(define (add-digits num)
  (define (add-digits-iter num sum)
    (if (= num 0)
        (if (< sum 10)
            sum
            (add-digits-iter sum 0))
        (add-digits-iter (quotient num 10) (+ sum (remainder num 10)))))
  (add-digits-iter num 0))


;; Example1 => 2
(add-digits 38)

;; Example2 => 5
(add-digits 9527)

;; Example3 => 8
(add-digits 8)
