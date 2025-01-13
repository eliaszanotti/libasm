global ft_read
extern __errno_location

section .text
	ft_read:
		cmp rdi, 0
		jl .error

		mov rax, 0
		syscall

		test rax, rax
		js .error
		ret

	.error:
		neg rax
		mov r8, rax
		call __errno_location wrt ..plt
		mov [rax], r8
		mov rax, -1
		ret