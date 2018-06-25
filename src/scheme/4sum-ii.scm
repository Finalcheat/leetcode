;; 454. 四数相加 II
;; https://leetcode-cn.com/problems/4sum-ii/description/

;; 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
;; 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -228 到 228 - 1 之间，最终结果不会超过 231 - 1 。

;; 例如:
;; 输入:
;; A = [ 1, 2]
;; B = [-2,-1]
;; C = [-1, 2]
;; D = [ 0, 2]
;; 输出:
;; 2
;; 解释:
;; 两个元组如下:
;; 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
;; 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0


;; Guile

(define (four-sum-count A B C D)
  (define (hash-get-num h key)
    (let ((value (hashq-ref h key)))
      (if (eq? value #f)
          0
          value)))
  (define (init-hash-table h A aidx B bidx)
    (cond ((not (< aidx (vector-length A))) h)
          ((< bidx (vector-length B)) (let ((key (+ (vector-ref A aidx) (vector-ref B bidx))))
                                        (begin (hashq-set! h key (+ (hash-get-num h key) 1))
                                               (init-hash-table h A aidx B (+ bidx 1)))))
          (else (init-hash-table h A (+ aidx 1) B 0))))
  (define (four-sum-count-iter h C cidx D didx count)
    (cond ((not (< cidx (vector-length C))) count)
          ((< didx (vector-length D)) (let ((num (- 0 (+ (vector-ref C cidx) (vector-ref D didx))))
                                            (didx (+ didx 1)))
                                        (four-sum-count-iter h C cidx D didx (+ count (hash-get-num h num)))))
          (else (four-sum-count-iter h C (+ cidx 1) D 0 count))))
  (four-sum-count-iter (init-hash-table (make-hash-table 100) A 0 B 0) C 0 D 0 0))


;; Example1 => 2
(define A (list->vector (list 1 2)))
(define B (list->vector (list -2 -1)))
(define C (list->vector (list -1 2)))
(define D (list->vector (list 0 2)))
(four-sum-count A B C D)
