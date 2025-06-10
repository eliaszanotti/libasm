global ft_strcpy

section .text
	ft_strcpy:
		;initialize the index to 0
		xor rcx, rcx

	.copy_loop:
		;load the byte from the source string into dl
		mov dl, [rsi + rcx]
		;store the byte in the destination string
		mov [rdi + rcx], dl
		;compare the byte with 0 (null terminator)
		cmp dl, 0
		je .exit
		inc rcx
		jmp .copy_loop

	.exit:
		;return the pointer to the destination string
		mov rax, rdi
		ret