;mvi a, 00fah
;mvi c, 00h
;mov b, a
;push b
;pop psw
;mvi d, 00h
;mvi e, 00h
;start: inr d
;jc stop
;rlc
;jnc start 
;inr e
;jmp start
;stop: hlt

mvi a, 00f0h
mvi c, 8h
mvi b, 00h
label: ral
jnc decr
inr b
decr: dcr c
jnz label
hlt

