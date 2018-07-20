mvi h, 34h
mvi d, 12h
mvi a, 0h
mov a, h
daa
mov h, a
mov a, d
daa
mov d, a
mov a, h
sub d
daa
mov h, a
hlt