;; 231. 2的幂
;; https://leetcode-cn.com/problems/power-of-two/description/

;; 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

;; 示例 1:
;; 输入: 1
;; 输出: true
;; 解释: 2^0 = 1

;; 示例 2:
;; 输入: 16
;; 输出: true
;; 解释: 2^4 = 16

;; 示例 3:
;; 输入: 218
;; 输出: false


;; Guile

(define (is-power-of-two n)
  (define (is-power-of-two-iter n one-num)
    (cond ((> one-num 1) 0)
          ((> n 0) (is-power-of-two-iter (quotient n 2) (+ one-num (logand n 1))))
          (else one-num)))
  (= (is-power-of-two-iter n 0) 1))


;; Example1 => #t
(is-power-of-two 1)


;; Example2 => #t
(is-power-of-two 16)


;; Example3 => #f
(is-power-of-two 218)
