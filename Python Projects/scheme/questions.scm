(define (caar x) (car (car x)))
(define (cadr x) (car (cdr x)))
(define (cdar x) (cdr (car x)))
(define (cddr x) (cdr (cdr x)))

; Some utility functions that you may find useful to implement.

(define (cons-all first rests)
    (define (proc a)
        (cons first a)
    )
    (map proc rests)  
)

(define (zip pairs)
  (list (map car pairs) (map cadr pairs))
)

;; Problem 17
;; Returns a list of two-element lists
(define (enumerate s)
  ; BEGIN PROBLEM 17
  (define (enumerator s count)
    (if (null? s)
        nil
        (cons (cons count (cons (car s) nil)) (enumerator (cdr s) (+ count 1)))
        )
  )
  (enumerator s 0)
  )
  ; END PROBLEM 17

;; Problem 18
;; List all ways to make change for TOTAL with DENOMS
(define (list-change total denoms)
  ; BEGIN PROBLEM 18
  (if (null? denoms) nil
      (if (eq? 0 total) (cons nil nil)
            (if (> (car denoms) total) (list-change total (cdr denoms))
                (append (cons-all (car denoms) (list-change (- total (car denoms)) denoms)) (list-change total (cdr denoms)))
            )
      )  
  )
  )
  ; END PROBLEM 18

;; Problem 19
;; Returns a function that checks if an expression is the special form FORM
(define (check-special form)
  (lambda (expr) (equal? form (car expr))))

(define lambda? (check-special 'lambda))
(define define? (check-special 'define))
(define quoted? (check-special 'quote))
(define let?    (check-special 'let))

;; Converts all let special forms in EXPR into equivalent forms using lambda
(define (let-to-lambda expr)
  (cond ((atom? expr)
         ; BEGIN PROBLEM 19
         expr
         ; END PROBLEM 19
         )
        ((quoted? expr)
         ; BEGIN PROBLEM 19
         expr
         ; END PROBLEM 19
         )
        ((or (lambda? expr)
             (define? expr))
         (let ((form   (car expr))
               (params (cadr expr))
               (body   (cddr expr)))
           ; BEGIN PROBLEM 19
           (cons form (cons params (map let-to-lambda body)))
           ; END PROBLEM 19
           ))
        ((let? expr)
         (let ((values (cadr expr))
               (body   (cddr expr)))
           ; BEGIN PROBLEM 19
           (cons (cons (quote lambda) (cons (car (zip values)) (map let-to-lambda body))) (map let-to-lambda (car (cdr (zip values)))))
           ; END PROBLEM 19
           ))
        (else
         ; BEGIN PROBLEM 19
         (cons (car expr) (map let-to-lambda (cdr expr)))
         ; END PROBLEM 19
         )))
