global ft_strcmp

section .text
	ft_strcmp:
		test rdi, rdi
		jz .inferior
		test rsi, rsi
		jz .inferior
		xor rcx, rcx

	.loop:
		mov al, [rdi + rcx]
		mov dl, [rsi + rcx]

		cmp al, dl
		jne .exit

		test al, al
		je .equal

		inc rcx
		jmp .loop

	.exit:
		cmp al, dl
		jl .inferior
		jg .superior

	.equal:
		xor rax, rax
		ret

	.inferior:
		mov rax, -1
		ret

	.superior:
		mov rax, 1
		ret

