;; 633. 平方数之和
;; https://leetcode-cn.com/problems/sum-of-square-numbers/description/

;; 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。

;; 示例1:
;; 输入: 5
;; 输出: True
;; 解释: 1 * 1 + 2 * 2 = 5

;; 示例2:
;; 输入: 3
;; 输出: False


;; Guile

(define (judge-square-sum c)
  (define (build-hash c)
    (define (build-hash-iter h first last)
      (if (> first last)
          h
          (begin (hash-set! h (* first first) #t)
                 (build-hash-iter h (+ first 1) last))))
    (build-hash-iter (make-hash-table 50) 0 (sqrt c)))
  (define (judge-square-sum-iter h first last c)
    (if (> first last)
        #f
        (let ((v (- c (* first first))))
          (cond ((< v 0) #f)
                ((eq? (hash-ref h v) #t) #t)
                (else (judge-square-sum-iter h (+ first 1) last c))))))
  (judge-square-sum-iter (build-hash c) 0 (sqrt c) c))


;; Example1 => #t
(judge-square-sum 5)


;; Example2 => #f
(judge-square-sum 3)
