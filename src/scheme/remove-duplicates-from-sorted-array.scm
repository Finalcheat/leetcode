;; 26. 删除排序数组中的重复项
;; https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/

;; 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
;; 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

;; 示例 1:
;; 给定数组 nums = [1,1,2],
;; 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
;; 你不需要考虑数组中超出新长度后面的元素。

;; 示例 2:
;; 给定 nums = [0,0,1,1,1,2,2,3,3,4],
;; 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
;; 你不需要考虑数组中超出新长度后面的元素。


;; Guile

(define (remove-duplicates nums)
  (define (remove-duplicates-iter nums idx prev-num prev-idx)
    (if (= idx (vector-length nums))
        prev-idx
        (let ((num (vector-ref nums idx))
              (idx (+ idx 1)))
          (if (= num prev-num)
              (remove-duplicates-iter nums idx prev-num prev-idx)
              (begin (vector-set! nums prev-idx num)
                     (remove-duplicates-iter nums idx num (+ prev-idx 1)))))))
  (if (= 0 (vector-length nums))
      0
      (remove-duplicates-iter nums 1 (vector-ref nums 0) 1)))


;; Example1 => 2
(define nums (list->vector (list 1 1 2)))
(remove-duplicates nums)


;; Example2 => 5
(define nums (list->vector (list 0 0 1 1 1 2 2 3 3 4)))
(remove-duplicates nums)

