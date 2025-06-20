global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

section .text
	ft_strdup:
        ;save the original string on the stack
        push rdi
        call ft_strlen
        ;add 1 to the length to include the null terminator
        inc rax

        ;allocate memory for the new string with the length of the original string (rax)
        mov rdi, rax
		;wrt ..plt is used to call the malloc function from the C library
        call malloc wrt ..plt
		;test if malloc failed (rax is 0)
        test rax, rax
        jz .error

        ;after malloc, rax is the address of the new string so we can use it as the destination string
        mov rdi, rax
        ;restore the original string address (and we save it in rsi) previously saved in the stack (push rdi)
        pop rsi
        ;rdi is the destination string, rsi is the source string
        call ft_strcpy
		;rax is the address of the new string
        ret

	.error:
		;restore the original string address from the stack
        pop rdi
		;set rax to 0 to indicate failure
        xor rax, rax
        ret