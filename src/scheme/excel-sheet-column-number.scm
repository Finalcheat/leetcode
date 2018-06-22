;; 171. Excel表列序号
;; https://leetcode-cn.com/problems/excel-sheet-column-number/description/

;; 给定一个Excel表格中的列名称，返回其相应的列序号。
;; 例如，
;; A -> 1
;; B -> 2
;; C -> 3
;; ...
;; Z -> 26
;; AA -> 27
;; AB -> 28
;; ...

;; 示例 1:
;; 输入: "A"
;; 输出: 1

;; 示例 2:
;; 输入: "AB"
;; 输出: 28

;; 示例 3:
;; 输入: "ZY"
;; 输出: 701


;; Guile

(define (title-to-number s)
  (define (title-to-number-iter s idx result pos)
    (if (< idx 0)
        result
        (let ((c (string-ref s idx))
              (idx (- idx 1)))
          (title-to-number-iter s idx (+ result (* (- (char->integer c) 64) pos)) (* pos 26)))))
  (title-to-number-iter s (- (string-length s) 1) 0 1))


;; Example1 => 1
(title-to-number "A")

;; Example2 => 28
(title-to-number "AB")

;; Example3 => 701
(title-to-number "ZY")
