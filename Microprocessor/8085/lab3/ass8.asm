lda 0030h
ani 20h
rlc
rlc
rlc
jc start
hlt
start: mvi a, 00ffh
out 40
hlt
