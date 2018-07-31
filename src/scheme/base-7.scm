;; 504. 七进制数
;; https://leetcode-cn.com/problems/base-7/description/

;; 给定一个整数，将其转化为7进制，并以字符串形式输出。

;; 示例 1:
;; 输入: 100
;; 输出: "202"

;; 示例 2:
;; 输入: -7
;; 输出: "-10"


;; Guile

(define (convert-to-base7 num)
  (define (build-v num)
    (define (build-l num)
      (if (= num 0)
          '()
          (cons (remainder num 7) (build-l (quotient num 7)))))
    (list->vector (build-l (abs num))))
  (define (convert-to-base7-iter v idx result)
    (if (< idx 0)
        result
        (let ((num (vector-ref v idx))
              (idx (- idx 1)))
          (convert-to-base7-iter v idx (+ (* result 10) num)))))
  (define v (build-v num))
  (let ((negative (if (< num 0) #t #f)))
    (let ((result (convert-to-base7-iter v (- (vector-length v) 1) 0)))
      (if (eq? negative #f)
          (number->string result)
          (string-append "-" (number->string result))))))


;; Example1 => "202"
(convert-to-base7 100)


;; Example2 => "-10"
(convert-to-base7 (- 7))
