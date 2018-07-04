;; 172. 阶乘后的零
;; https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/

;; 给定一个整数 n，返回 n! 结果尾数中零的数量。

;; 示例 1:
;; 输入: 3
;; 输出: 0
;; 解释: 3! = 6, 尾数中没有零。

;; 示例 2:
;; 输入: 5
;; 输出: 1
;; 解释: 5! = 120, 尾数中有 1 个零.


;; Guile

(define (trailing-zeroes n)
  (define (trailing-zeroes-iter n count)
    (if (> n 0)
        (let ((num (quotient n 5)))
          (trailing-zeroes-iter num (+ count num)))
        count))
  (trailing-zeroes-iter n 0))


;; Example1 => 0
(trailing-zeroes 3)


;; Example2 => 1
(trailing-zeroes 5)
