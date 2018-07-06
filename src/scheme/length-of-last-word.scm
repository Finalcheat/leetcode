;; 58. 最后一个单词的长度
;; https://leetcode-cn.com/problems/length-of-last-word/description/

;; 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
;; 如果不存在最后一个单词，请返回 0 。
;; 说明：一个单词是指由字母组成，但不包含任何空格的字符串。

;; 示例:
;; 输入: "Hello World"
;; 输出: 5


;; Guile

(define (length-of-last-word s)
  (define (length-of-last-word-last-iter s idx)
    (if (or (< idx 0) (not (eq? (string-ref s idx) #\space)))
        idx
        (length-of-last-word-last-iter s (- idx 1))))
  (define (length-of-last-word-first-iter s idx)
    (if (or (< idx 0) (eq? (string-ref s idx) #\space))
        idx
        (length-of-last-word-first-iter s (- idx 1))))
  (let ((last (length-of-last-word-last-iter s (- (string-length s) 1))))
    (let ((first (length-of-last-word-first-iter s last)))
      (- last first))))


;; Example1 => 5
(length-of-last-word "Hello World")


;; Example2 => 4
(length-of-last-word "  Length  Of Last    Word    ")
