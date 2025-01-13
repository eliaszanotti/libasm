global ft_write
extern __errno_location

section .text
	ft_write:
		cmp rdi, 0
		jl .error

		mov rax, 1
		syscall

		test rax, rax
		js .error

		pop rbp
		ret

	.error:
		neg rax
		mov r8, rax
		call __errno_location wrt ..plt
		mov [rax], r8
		mov rax, -1
		pop rbp
		ret