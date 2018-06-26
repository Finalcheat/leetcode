;; 300. 最长上升子序列
;; https://leetcode-cn.com/problems/longest-increasing-subsequence/description/

;; 给定一个无序的整数数组，找到其中最长上升子序列的长度。

;; 示例:
;; 输入: [10,9,2,5,3,7,101,18]
;; 输出: 4
;; 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

;; 说明:
;; * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
;; * 你算法的时间复杂度应该为 O(n2) 。


;; Guile

(define (length-of-LIS nums)
  (define (dp-max dp i j)
    (let ((d1 (vector-ref dp i))
          (d2 (+ (vector-ref dp j) 1)))
      (if (< d1 d2)
          d2
          d1)))
  (define (length-of-LIS-iter nums i j dp)
    (let ((nums-len (vector-length nums)))
      (if (not (< i nums-len))
          dp
          (cond ((not (< j i)) (length-of-LIS-iter nums (+ i 1) 0 dp))
                ((< (vector-ref nums j) (vector-ref nums i)) (begin (vector-set! dp i (dp-max dp i j))
                                                                    (length-of-LIS-iter nums i (+ j 1) dp)))
                (else (length-of-LIS-iter nums i (+ j 1) dp))))))
  (length-of-LIS-iter nums 1 0 (make-vector (vector-length nums) 1)))


(define (vector-max dp)
  (define (vector-max-iter dp idx max-num)
    (if (not (< idx (vector-length dp)))
        max-num
        (cond ((< max-num (vector-ref dp idx)) (vector-max-iter dp (+ idx 1) (vector-ref dp idx)))
              (else (vector-max-iter dp (+ idx 1) max-num)))))
  (let ((len (vector-length dp)))
    (if (= len 0)
        0
        (let ((max-num (vector-ref dp 0)))
          (vector-max-iter dp 1 max-num)))))


;; Example1 => 4
(define dp (length-of-LIS (list->vector (list 1 7 2 8 3 4))))
(vector-max dp)


;; Example2 => 6
(define dp (length-of-LIS (list->vector (list 10 9 2 5 3 7 101 110 18 19 35))))
(vector-max dp)


;; Example3 => 4
(define dp (length-of-LIS (list->vector (list 10 9 2 5 3 7 101 18))))
(vector-max dp)
