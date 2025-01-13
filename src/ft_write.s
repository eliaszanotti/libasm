global ft_write

section .text
	ft_write:
		cmp rdi, 0
		jl .error


		mov rax, 1
		syscall

		test rax, rax
		js .error
		ret

	.error:
		mov rax, -1
		ret
