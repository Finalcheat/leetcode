;; 翻转图像
;; https://leetcode-cn.com/problems/flipping-an-image/description/

;; 给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。
;; 水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。
;; 反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。

;; 示例 1:
;; 输入: [[1,1,0],[1,0,1],[0,0,0]]
;; 输出: [[1,0,0],[0,1,0],[1,1,1]]
;; 解释: 首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
;; 然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]

;; 示例 2:
;; 输入: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
;; 输出: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
;; 解释: 首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
;; 然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]


;; Guile

(define (flip-and-invert-image A)
  (define (array-flip arr)
    (define (array-swap arr i j)
      (let ((tmp (array-ref arr i)))
        (begin (array-set! arr (array-ref arr j) i) (array-set! arr tmp j))))
    (define (array-flip-iter arr first last)
      (if (>= first last)
          arr
          (begin (array-swap arr first last) (array-flip-iter arr (+ first 1) (- last 1)))))
    (array-flip-iter arr 0 (- (array-length arr) 1)))
  (define (array-invert arr)
    (define (invert-val x)
      (cond ((> x 0) 0)
            (else 1)))
    (define (array-invert-iter arr idx)
      (if (< idx 0)
          arr
          (begin (array-set! arr (invert-val (array-ref arr idx)) idx) (array-invert-iter arr (- idx 1)))))
    (array-invert-iter arr (- (array-length arr) 1)))
  (define (flip-and-invert-image-iter A1)
    (if (eq? '() A1)
        A
        (let ((arr (car A1)))
          (begin (array-flip arr) (array-invert arr) (flip-and-invert-image-iter (cdr A1))))))
  (flip-and-invert-image-iter A))


;; Example1
(define r1 (list->array 1 (list 1 1 0)))
(define r2 (list->array 1 (list 1 0 1)))
(define r3 (list->array 1 (list 0 0 0)))
(define rows (list r1 r2 r3))
(flip-and-invert-image rows)


;; Example2
(define r1 (list->array 1 (list 1 1 0 0)))
(define r2 (list->array 1 (list 1 0 0 1)))
(define r3 (list->array 1 (list 0 1 1 1)))
(define r4 (list->array 1 (list 1 0 1 0)))
(define rows (list r1 r2 r3 r4))
(flip-and-invert-image rows)

