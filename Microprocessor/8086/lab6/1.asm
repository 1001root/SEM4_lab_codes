;title to add two numbers
	cpu 8086
	section.model small
	section.stack 32
	section.data
val1 dw 1234h
val2 dw 2345h
sum dw ?
	.code
main proc far
	mov ax, @data
	mov ds, ax
	
	mov ax, val1
	add ax, val2
	mov sum, ax
	
	mov ax, 4c00h
	int 21h
main endp
	end main

