global ft_strcmp

section .text
	ft_strcmp:
		;initialize the index to 0
		xor rcx, rcx

	.loop:
		;check if both strings reached null terminator
		cmp [rdi + rcx], byte 0 
		je .exit
		cmp [rsi + rcx], byte 0 
		je .exit
		;load character from second string
		mov dl, byte [rsi + rcx]
		;compare characters from both strings
		cmp byte [rdi + rcx], dl
		jne .exit
		inc rcx
		jmp .loop

	.exit:
		;load current character from first string (mov zero-extended is a mov instruction that adds 0 to the left of the byte)
		movzx rax, byte [rdi + rcx]
		movzx rdx, byte [rsi + rcx]
		;rax = str1[i] and rdx = str2[i]
		sub rax, rdx
		ret