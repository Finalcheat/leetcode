;; 344. 反转字符串
;; https://leetcode-cn.com/problems/reverse-string/description/

;; 请编写一个函数，其功能是将输入的字符串反转过来。

;; 示例：
;; 输入：s = "hello"
;; 返回："olleh"

;; Guile

(define (reverse-string s)
  (define (swap s i j)
    (let ((tmp (string-ref s i)))
      (begin (string-set! s i (string-ref s j)) (string-set! s j tmp))))
  (define (reverse-string-iter s first last)
    (if (>= first last)
        s
        (begin (swap s first last) (reverse-string-iter s (+ first 1) (- last 1)))))
  (let ((len (string-length s)))
    (if (> len 0)
        (reverse-string-iter s 0 (- len 1))
        s)))


;; Example1
(reverse-string (string-append "hello"))

