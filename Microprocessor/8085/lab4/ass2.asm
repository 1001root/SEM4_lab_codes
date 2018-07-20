lxi b, 00ffh
push b
pop psw
;lhld d, psw
push psw
pop d
mov a, e
ori 10h
ani 00fbh
mov e,a
push d
pop psw
hlt
