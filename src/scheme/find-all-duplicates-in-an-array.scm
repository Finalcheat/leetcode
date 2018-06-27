;; 442. 数组中重复的数据
;; https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/description/

;; 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
;; 找到所有出现两次的元素。
;; 你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

;; 示例：
;; 输入:
;; [4,3,2,7,8,2,3,1]
;; 输出:
;; [2,3]


;; Guile

(define (find-duplicates nums)
  (define (find-duplicates-iter nums idx)
    (if (= idx (vector-length nums))
        '()
        (let ((num-idx (- (abs (vector-ref nums idx)) 1))
              (idx (+ idx 1)))
          (let ((num (vector-ref nums num-idx)))
            (if (> num 0)
                (begin (vector-set! nums num-idx (- 0 num)) (find-duplicates-iter nums idx))
                (cons (+ num-idx 1) (find-duplicates-iter nums idx)))))))
  (find-duplicates-iter nums 0))


;; Example1 => (2 3)
(find-duplicates (list->vector (list 4 3 2 7 8 2 3 1)))


;; Example2 => (8 1)
(find-duplicates (list->vector (list 4 3 1 8 8 2 6 1)))
