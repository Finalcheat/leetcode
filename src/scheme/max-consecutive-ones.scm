;; 485. 最大连续1的个数
;; https://leetcode-cn.com/problems/max-consecutive-ones/description/

;; 给定一个二进制数组， 计算其中最大连续1的个数。

;; 示例 1:
;; 输入: [1,1,0,1,1,1]
;; 输出: 3
;; 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.

;; Guile

(define (find-max-consecutive-ones nums)
  (define (max-num a b)
    (if (> a b)
        a
        b))
  (define (find-max-consecutive-ones-iter nums max count)
    (if (eq? nums '())
        (max-num max count)
        (let ((num (car nums))
              (cdr-num (cdr nums)))
          (if (= num 1)
              (find-max-consecutive-ones-iter cdr-num max (+ count 1))
              (begin (set! max (max-num max count))
                     (find-max-consecutive-ones-iter cdr-num max 0))))))
  (find-max-consecutive-ones-iter nums 0 0))


;; Example1
(find-max-consecutive-ones (list 1 1 0 1 1 1))

;; Example2
(find-max-consecutive-ones (list 1 0 1 1 1 1 0 1 1 1 0 1 1 1))

;; Example3
(find-max-consecutive-ones (list 1 1 1 1 0 1 0 1 1 0 1 0 1 0 1 1 1))
