mvi a, 80
out 43
mvi a, 00h
lxi h, 000bh
pchl
rst 5
mvi a, 00h
out 40
adi 01h
jnc 000bh