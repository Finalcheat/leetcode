;; 657. 判断路线成圈
;; https://leetcode-cn.com/problems/judge-route-circle/description/

;; 初始位置 (0, 0) 处有一个机器人。给出它的一系列动作，判断这个机器人的移动路线是否形成一个圆圈，换言之就是判断它是否会移回到原来的位置。
;; 移动顺序由一个字符串表示。每一个动作都是由一个字符来表示的。机器人有效的动作有 R（右），L（左），U（上）和 D（下）。输出应为 true 或 false，表示机器人移动路线是否成圈。

;; 示例 1:
;; 输入: "UD"
;; 输出: true

;; 示例 2:
;; 输入: "LL"
;; 输出: false


;; Guile

(define (judgeCircle moves)
  (define (circle-iter moves idx len horizontal vertical)
    (cond ((>= idx len) (if (and (eq? horizontal 0)
                                 (eq? vertical 0))
                            #t
                            #f))
          (else (let ((c (string-ref moves idx))
                      (idx (+ idx 1)))
                  (cond ((eq? c #\R) (circle-iter moves idx len (+ horizontal 1) vertical))
                        ((eq? c #\L) (circle-iter moves idx len (- horizontal 1) vertical))
                        ((eq? c #\U) (circle-iter moves idx len horizontal (+ vertical 1)))
                        (else (circle-iter moves idx len horizontal (- vertical 1))))))))
  (circle-iter moves 0 (string-length moves) 0 0))


;; #t
(judgeCircle "UD")


;; #f
(judgeCircle "LL")
