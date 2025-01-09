global ft_strcpy

section .text
	ft_strcpy:
		test rdi, rdi
		jz .dest_null
		test rsi, rsi
		jz .src_null
		xor rax, rax

	.copy_loop:
		mov al, [rsi + rax]
		mov [rdi + rax], al
		inc rax
		cmp al, 0
		jne .copy_loop
		ret

	.dest_null:
		mov rdi, rsi
		ret

	.src_null:
		ret