;; 551. 学生出勤纪录 I
;; https://leetcode-cn.com/problems/student-attendance-record-i/description/

;; 给定一个字符串来代表一个学生的出勤纪录，这个纪录仅包含以下三个字符：
;; 1. 'A' : Absent，缺勤
;; 2. 'L' : Late，迟到
;; 3. 'P' : Present，到场
;; 如果一个学生的出勤纪录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
;; 你需要根据这个学生的出勤纪录判断他是否会被奖赏。

;; 示例 1:
;; 输入: "PPALLP"
;; 输出: True

;; 示例 2:
;; 输入: "PPALLL"
;; 输出: False


;; Guile

(define (check-record s)
  (define (check-record-iter s idx absent-count late-count)
    (cond ((or (> absent-count 1) (> late-count 2)) #f)
          ((= idx (string-length s)) #t)
          (else (let ((c (string-ref s idx))
                      (idx (+ idx 1)))
                  (cond ((eq? c #\A) (check-record-iter s idx (+ absent-count 1) 0))
                        ((eq? c #\L) (check-record-iter s idx absent-count (+ late-count 1)))
                        (else (check-record-iter s idx absent-count 0)))))))
  (check-record-iter s 0 0 0))


;; Example1 => #t
(check-record "PPALLP")


;; Example2 => #f
(check-record "PPALLL")
