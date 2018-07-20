mvi a, 80h
out 40
mvi d, 00h
;lxi b, 0000h
start: mov a, d
;loop2: mvi c, 00ffh
;dcr c
;jnz loop2
lxi b, 0000h
loop: inr c
jnz loop
inr b
jnz loop
out 40
inr d
jnz start
hlt