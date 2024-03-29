(define (fast-multiply b c)
  (define (double n)
    (+ n n))
  (define (halve n)
    (/ n 2))
  (define (iter a b c)
    (cond ((= c 0) a)
      ((even? c) (iter a (double b) (halve c)))
      (else (iter (+ a b) (double b) (halve (- c 1))))))
  (iter 0 b c))
