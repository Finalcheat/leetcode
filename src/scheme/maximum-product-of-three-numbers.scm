;; 628. 三个数的最大乘积
;; https://leetcode-cn.com/problems/maximum-product-of-three-numbers/description/

;; 给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

;; 示例 1:
;; 输入: [1,2,3]
;; 输出: 6

;; 示例 2:
;; 输入: [1,2,3,4]
;; 输出: 24


;; Guile

(define (maximum-product nums)
  (define sort-nums (sort nums >))
  (let ((max-num (vector-ref sort-nums 0))
        (len (vector-length sort-nums)))
    (let ((num1 (* max-num (vector-ref sort-nums 1) (vector-ref sort-nums 2)))
          (num2 (* max-num (vector-ref sort-nums (- len 1)) (vector-ref sort-nums (- len 2)))))
      (if (< num1 num2)
          num2
          num1))))


;; Example1 => 6
(maximum-product (list->vector (list 1 2 3)))


;; Example2 => 24
(maximum-product (list->vector (list 1 2 3 4)))


;; Example3 => 1000
(maximum-product (list->vector (list 1 3 -1 -5 200)))
