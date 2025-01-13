global ft_strcmp

section .text
	ft_strcmp:
		xor rcx, rcx

	.loop:
		cmp [rdi + rcx], byte 0 
		je .exit
		cmp [rsi + rcx], byte 0 
		je .exit
		mov dl, byte [rsi + rcx]
		cmp byte [rdi + rcx], dl
		jne .exit
		inc rcx
		jmp .loop

	.exit:
		movzx rax, byte [rdi + rcx]
		movzx rdx, byte [rsi + rcx]
		sub rax, rdx
		ret