;; 415. 字符串相加
;; https://leetcode-cn.com/problems/add-strings/description/

;; 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
;; 注意：
;; 1. num1 和num2 的长度都小于 5100.
;; 2. num1 和num2 都只包含数字 0-9.
;; 3. num1 和num2 都不包含任何前导零。
;; 4. 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。


;; Guile

(define (add-strings num1 num2)
  (define (string-get-value num idx)
    (if (< idx 0)
        0
        (- (char->integer (string-ref num idx)) (char->integer #\0))))
  (define (add-strings-iter num1 idx1 num2 idx2 result idx carry)
    (if (or (> idx1 0) (> idx2 0))
        (let ((idx1 (- idx1 1))
              (idx2 (- idx2 1))
              (idx (- idx 1)))
          (let ((n1 (string-get-value num1 idx1))
                (n2 (string-get-value num2 idx2)))
            (let ((sum (+ n1 n2 carry)))
              (let ((carry (quotient sum 10))
                    (sum (remainder sum 10)))
                (begin (string-set! result idx (integer->char (+ sum (char->integer #\0))))
                       (add-strings-iter num1 idx1 num2 idx2 result idx carry))))))
        carry))
  (define idx1 (string-length num1))
  (define idx2 (string-length num2))
  (define idx (max idx1 idx2))
  (define result (make-string idx #\0))
  (let ((carry (add-strings-iter num1 idx1 num2 idx2 result idx 0)))
    (if (> carry 0)
        (string-append (number->string carry) result)
        result)))


;; Example1 => "579"
(add-strings "123" "456")


;; Example2 => "122211"
(add-strings "54321" "67890")


;; Example3 => "123456890"
(add-strings "123456789" "101")
