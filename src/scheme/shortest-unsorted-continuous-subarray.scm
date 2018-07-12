;; 581. 最短无序连续子数组
;; https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/

;; 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
;; 你找到的子数组应是最短的，请输出它的长度。

;; 示例 1:
;; 输入: [2, 6, 4, 8, 10, 9, 15]
;; 输出: 5
;; 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。


;; Guile

(define (find-unsorted-subarray nums)
  (define (find-unsorted-subarray-first-iter nums v idx)
    (if (and (< idx (vector-length nums)) (= (vector-ref nums idx) (vector-ref v idx)))
        (find-unsorted-subarray-first-iter nums v (+ idx 1))
        idx))
  (define (find-unsorted-subarray-last-iter nums v first last)
    (if (and (> last first) (= (vector-ref nums last) (vector-ref v last)))
        (find-unsorted-subarray-last-iter nums v first (- last 1))
        last))
  (let ((v (sort nums <)))
    (let ((i (find-unsorted-subarray-first-iter nums v 0)))
      (let ((j (find-unsorted-subarray-last-iter nums v i (- (vector-length nums) 1))))
        (+ (- j i) 1)))))


;; Example1 => 5
(find-unsorted-subarray (list->vector (list 2 6 4 8 10 9 15)))
