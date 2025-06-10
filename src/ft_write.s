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
		;negate the value of rax (syscall errors are negative but we need to return a positive value in errno)
		neg rax
		mov r8, rax
		;return the address of errno
		call __errno_location wrt ..plt
		;store the value of r8 in the address of errno ([rax] = errno address)
		mov [rax], r8
		;-1 is the return value for error
		mov rax, -1
		ret