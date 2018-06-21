;; 804. 唯一摩尔斯密码词
;; https://leetcode-cn.com/problems/unique-morse-code-words/description/

;; 国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串，
;; 比如: "a" 对应 ".-", "b" 对应 "-...", "c" 对应 "-.-.", 等等。
;; 为了方便，所有26个英文字母对应摩尔斯密码表如下：
;; [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
;; 给定一个单词列表，每个单词可以写成每个字母对应摩尔斯密码的组合。例如，"cab" 可以写成 "-.-.-....-"，(即 "-.-." + "-..." + ".-"字符串的结合)。我们将这样一个连接过程称作单词翻译。
;; 返回我们可以获得所有词不同单词翻译的数量。

;; 例如:
;; 输入: words = ["gin", "zen", "gig", "msg"]
;; 输出: 2
;; 解释:
;; 各单词翻译如下:
;; "gin" -> "--...-."
;; "zen" -> "--...-."
;; "gig" -> "--...--."
;; "msg" -> "--...--."
;; 共有 2 种不同翻译, "--...-." 和 "--...--.".


;; Guile

(define (unique-morse-representations words)
  (define (init-hash-table)
    (define h (make-hash-table 26))
    (hash-set! h #\a ".-")
    (hash-set! h #\b "-...")
    (hash-set! h #\c "-.-.")
    (hash-set! h #\d "-..")
    (hash-set! h #\e ".")
    (hash-set! h #\f "..-.")
    (hash-set! h #\g "--.")
    (hash-set! h #\h "....")
    (hash-set! h #\i "..")
    (hash-set! h #\j ".---")
    (hash-set! h #\k "-.-")
    (hash-set! h #\l ".-..")
    (hash-set! h #\m "--")
    (hash-set! h #\n "-.")
    (hash-set! h #\o "---")
    (hash-set! h #\p ".--.")
    (hash-set! h #\q "--.-")
    (hash-set! h #\r ".-.")
    (hash-set! h #\s "...")
    (hash-set! h #\t "-")
    (hash-set! h #\u "..-")
    (hash-set! h #\v "...-")
    (hash-set! h #\w ".--")
    (hash-set! h #\x "-..-")
    (hash-set! h #\y "-.--")
    (hash-set! h #\z "--..")
    h)
  (define (word-encode h word)
    (define (word-encode-iter h word idx)
      (if (< idx (string-length word))
          (let ((encode (hash-ref h (string-ref word idx))))
            (string-append encode (word-encode-iter h word (+ idx 1))))
          ""))
    (word-encode-iter h word 0))
  (define (unique-morse-representations-iter words h1 h2 count)
    (if (eq? words '())
        count
        (let ((word (car words)))
          (let ((encode (word-encode h1 word)))
            (let ((find (hash-ref h2 encode)))
              (if (eq? find #f)
                  (begin (hash-set! h2 encode #t)
                         (unique-morse-representations-iter (cdr words) h1 h2 (+ count 1)))
                  (unique-morse-representations-iter (cdr words) h1 h2 count)))))))
  (unique-morse-representations-iter words (init-hash-table) (make-hash-table 26) 0))


;; Example1 => 2
(unique-morse-representations (list "gin" "zen" "gig" "msg"))
