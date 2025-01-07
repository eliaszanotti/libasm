section .text
global ft_strlen
extern errno_location

ft_strlen:
    test rdi, rdi
    jz .null_string

    xor rax, rax
    xor rcx, rcx

.loop:
    cmp byte [rdi + rcx], 0
    je .done
    inc rax
    inc rcx
    jmp .loop

.done:
    ret

.null_string:
    xor rax, rax
    call errno_location
    mov dword [rax], 22
    ret
