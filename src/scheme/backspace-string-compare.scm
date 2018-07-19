;; 844. 比较含退格的字符串
;; https://leetcode-cn.com/problems/backspace-string-compare/description/

;; 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

;; 示例 1：
;; 输入：S = "ab#c", T = "ad#c"
;; 输出：true
;; 解释：S 和 T 都会变成 “ac”。

;; 示例 2：
;; 输入：S = "ab##", T = "c#d#"
;; 输出：true
;; 解释：S 和 T 都会变成 “”。

;; 示例 3：
;; 输入：S = "a##c", T = "#a#c"
;; 输出：true
;; 解释：S 和 T 都会变成 “c”。

;; 示例 4：
;; 输入：S = "a#c", T = "b"
;; 输出：false
;; 解释：S 会变成 “c”，但 T 仍然是 “b”。


;; Guile

(define (backspace-compare S T)
  (define (build-ss S)
    (define (build-ss-iter S idx ss)
      (if (= idx (string-length S))
          ss
          (let ((c (string-ref S idx))
                (idx (+ idx 1)))
            (cond ((eq? c #\#) (if (string-null? ss)
                                   (build-ss-iter S idx ss)
                                   (build-ss-iter S idx (substring ss 0 (- (string-length ss) 1)))))
                  (else (build-ss-iter S idx (string-append ss (make-string 1 c))))))))
    (build-ss-iter S 0 ""))
  ;; (build-ss T))
  (string=? (build-ss S) (build-ss T)))


;; Example1 => #t
(backspace-compare "ab#c" "ad#c")


;; Example2 => #t
(backspace-compare "ab##" "c#d#")


;; Example3 => #t
(backspace-compare "a##c" "#a#c")


;; Example4 => #f
(backspace-compare "a#c" "b")
