global _start

section .data
    msg db "What is your name? : ", 0    ; Message string
    len          equ $ - msg        ; Message length
    EXIT_SUCCESS equ 0
    sys_exit     equ 60

section .bss
    name resb 50

section .text
    

_print:
    
    

_exit_program:
    mov rax, sys_exit
    mov rdi, EXIT_SUCCESS
    syscall

_start:

    movq %rsp, %rbp

    pop %rbp


;     mov rdx, len                ; Message length
;     mov rsi, msg                ; Message pointer
;     mov rdi, 1                  ; File descriptor (stdout)
;     mov rax, 1                  ; Syscall number for printf
;     syscall

; ; Exiting, inform kernel
;     mov ebx, EXIT_SUCCESS       ; Process exit code
;     mov rax, sys_exit           ; Syscall number (sys_exit)
;     syscall