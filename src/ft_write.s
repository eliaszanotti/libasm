global ft_write
extern __errno_location

section .text
	ft_write:
		cmp rdi, 0
		;jump if sign (negative)
		js .error

		;syscall instruction is used to call the kernel (0 is read, 1 is write)
		mov rax, 1
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