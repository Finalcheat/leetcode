;; 462. 最少移动次数使数组元素相等 II
;; https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/description/

;; 给定一个非空整数数组，找到使所有数组元素相等所需的最小移动数，其中每次移动可将选定的一个元素加1或减1。 您可以假设数组的长度最多为10000。

;; 例如:
;; 输入:
;; [1,2,3]
;; 输出:
;; 2
;; 说明：
;; 只有两个动作是必要的（记得每一步仅可使其中一个元素加1或减1）：
;; [1,2,3]  =>  [2,2,3]  =>  [2,2,2]


;; Guile

(define (min-moves2 nums)
  (define (min-moves2-iter nums idx mid result)
    (if (= idx (vector-length nums))
        result
        (let ((num (vector-ref nums idx))
              (idx (+ idx 1)))
          (min-moves2-iter nums idx mid (+ result (abs (- mid num)))))))
  (define sort-nums (sort nums <))
  (if (= (vector-length nums) 0)
      0
      (let ((mid (vector-ref sort-nums (floor-quotient (vector-length nums) 2))))
        (min-moves2-iter sort-nums 0 mid 0))))


;; Example1 => 2
(min-moves2 (list->vector (list 1 2 3)))
