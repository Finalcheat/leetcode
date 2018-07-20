;; 506. 相对名次
;; https://leetcode-cn.com/problems/relative-ranks/description/

;; 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。
;; (注：分数越高的选手，排名越靠前。)

;; 示例 1:
;; 输入: [5, 4, 3, 2, 1]
;; 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
;; 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
;; 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。


;; Guile

(define (find-relative-ranks nums)
  (define (build-ranks nums idx)
    (if (= idx (vector-length nums))
        '()
        (cons (cons (vector-ref nums idx) idx) (build-ranks nums (+ idx 1)))))
  (define (find-relative-ranks-iter ranks idx result)
    (if (eq? ranks '())
        result
        (begin (let ((rank (car ranks)))
                 (let ((num (car rank))
                       (index (cdr rank)))
                   (cond ((= idx 0) (vector-set! result index "Gold Medal"))
                         ((= idx 1) (vector-set! result index "Silver Medal"))
                         ((= idx 2) (vector-set! result index "Bronze Medal"))
                         (else (vector-set! result index (number->string (+ idx 1)))))))
               (find-relative-ranks-iter (cdr ranks) (+ idx 1) result))))
  (define ranks (sort-list (build-ranks nums 0)
                           (lambda (l1 l2)
                             (let ((s1 (car l1))
                                   (s2 (car l2)))
                               (if (> s1 s2)
                                   #t
                                   #f)))))
  (find-relative-ranks-iter ranks 0 (make-vector (vector-length nums))))


;; Example1 => #("Gold Medal" "Silver Medal" "Bronze Medal" "4" "5")
(find-relative-ranks (list->vector (list 5 4 3 2 1)))


;; Example2 => #("Bronze Medal" "4" "6" "7" "Gold Medal" "5" "Silver Medal")
(find-relative-ranks (list->vector (list 90 88 76 34 100 78 98)))
