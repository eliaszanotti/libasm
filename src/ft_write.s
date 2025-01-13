global ft_write
extern	__errno_location

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
		neg rax ; pas necessaire, a tester
		mov rdi, rax
		call __errno_location wrt ..plt
		mov rax, rdi
		mov rax, -1
		ret