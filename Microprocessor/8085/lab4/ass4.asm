mvi a, 80h
out 40
mvi d, 33h
mvi e, 00h
lxi b, 0000h
mvi a, 00h
start: dcr d
jz stop  
inr e
mov a, c
add e
mov c, a
jnc start
inr b
jmp start
stop: mov a, c 
out 40
mov a, b
out 41
hlt
