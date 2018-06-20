;; 9. 回文数
;; https://leetcode-cn.com/problems/palindrome-number/description/

;; 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

;; 示例 1:
;; 输入: 121
;; 输出: true

;; 示例 2:
;; 输入: -121
;; 输出: false
;; 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

;; 示例 3:
;; 输入: 10
;; 输出: false
;; 解释: 从右向左读, 为 01 。因此它不是一个回文数。

;; Guile

(define (is-palindrome x)
  (define (reverse-num x)
    (define (reverse-num-iter x sum)
      (if (= x 0)
          sum
          (let ((q (quotient x 10))
                (r (remainder x 10)))
            (reverse-num-iter q (+ (* sum 10) r)))))
    (reverse-num-iter x 0))
  (if (< x 0)
      #f
      (eq? x (reverse-num x))))


;; Example1 => #t
(is-palindrome 121)

;; Example2 => #f
(is-palindrome -121)

;; Example3 => #f
(is-palindrome 10)

;; Example4 => #t
(is-palindrome 12113456765431121)
