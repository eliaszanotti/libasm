global ft_strcpy

section .text
	ft_strcpy:
		xor rcx, rcx

	.copy_loop:
		mov dl, [rsi + rcx]
		mov [rdi + rcx], dl
		cmp dl, 0
		je .exit
		inc rcx
		jmp .copy_loop

	.exit:
		mov rax, rdi
		ret