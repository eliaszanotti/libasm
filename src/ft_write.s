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
		ret

	.error:
		mov rbx, rax
		neg rbx
		call __errno_location
		mov [rax], rbx
		mov rax, -1
		ret