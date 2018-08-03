;; 405. 数字转换为十六进制数
;; https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/description/

;; 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
;; 注意:
;; 1. 十六进制中所有字母(a-f)都必须是小写。
;; 2. 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。
;; 3. 给定的数确保在32位有符号整数范围内。
;; 4. 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。

;; 示例 1：
;; 输入:
;; 26
;; 输出:
;; "1a"


;; Guile

(define (to-hex num)
  (define (build-vector num)
    (define (build-vector-iter num v idx)
      (if (= num 0)
          idx
          (begin (vector-set! v idx (remainder num 16))
                 (build-vector-iter (quotient num 16) v (+ idx 1)))))
    (define v (make-vector 50))
    (cons (build-vector-iter num v 0) v))
  (define (to-hex-iter v idx result)
    (if (< idx 0)
        result
        (let ((c (vector-ref v idx))
              (idx (- idx 1)))
          (cond ((= c 10) (to-hex-iter v idx (string-append result "a")))
                ((= c 11) (to-hex-iter v idx (string-append result "b")))
                ((= c 12) (to-hex-iter v idx (string-append result "c")))
                ((= c 13) (to-hex-iter v idx (string-append result "d")))
                ((= c 14) (to-hex-iter v idx (string-append result "e")))
                ((= c 15) (to-hex-iter v idx (string-append result "f")))
                (else (to-hex-iter v idx (string-append result (number->string c))))))))
  (define v-cons (build-vector num))
  (to-hex-iter (cdr v-cons) (- (car v-cons) 1) (string-append "")))


;; Example1 => "1a"
(to-hex 26)
