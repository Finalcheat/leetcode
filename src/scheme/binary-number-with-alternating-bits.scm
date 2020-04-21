;; 693. 交替位二进制数
;; https://leetcode-cn.com/problems/binary-number-with-alternating-bits/description/

;; 给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。

;; 示例 1:
;; 输入: 5
;; 输出: True
;; 解释:
;; 5的二进制数是: 101

;; 示例 2:
;; 输入: 7
;; 输出: False
;; 解释:
;; 7的二进制数是: 111

;; 示例 3:
;; 输入: 11
;; 输出: False
;; 解释:
;; 11的二进制数是: 1011

;; 示例 4:
;; 输入: 10
;; 输出: True
;; 解释:
;; 10的二进制数是: 1010


;; Guile

(define (has-alternating-bits n)
  (define (has-alternating-bits-iter n prev-bit)
    (if (= n 0)
        #t
        (if (= (remainder n 2) prev-bit)
            #f
            (has-alternating-bits-iter (quotient n 2) (abs (- prev-bit 1))))))
  (has-alternating-bits-iter (quotient n 2) (remainder n 2)))


;; Example1 => #t
(has-alternating-bits 5)


;; Example2 => #f
(has-alternating-bits 7)


;; Example3 => #f
(has-alternating-bits 11)


;; Example4 => #t
(has-alternating-bits 10)
