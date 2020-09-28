;Problem Statement: Write X86/64 ALP to perform multiplication of two 8-bit hexadecimal numbers.
;Use  successive addition and add and shift method. (use of 64-bit registers is expected) 


;********************************************
;Assignment no:4B
;........................................
;Title:Multiplication using Add & Shift method
;*********************************************

section .data

welmsg db 10,'Multiplication using Add & Shift method',10
welmsg_len equ $-welmsg

nummsg db 10,'Enter two digits of Number::'
nummsg_len equ $-nummsg

resmsg db 10,'Multiplication of elements::'
resmsg_len equ $-resmsg

blankmsg db 10,'',10
blank_len equ $-blankmsg

;**********.bss Section**********************

section .bss

    numascii resb 03
    num1 resb 02
    num2 resb 02
    result resb 02
    dispbuff resb 04

%macro display 2
    mov rax,01
    mov rdi,01
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

%macro accept 2
    mov rax,00
    mov rdi,00
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

;**********.text Section**********************
section .text
global _start
_start:

    display welmsg,welmsg_len

    display nummsg,nummsg_len
    accept numascii,3
    call packnum
    mov byte[num1],bl

    display nummsg,nummsg_len
    accept numascii,3
    call packnum
    mov byte[num2],bl

    mov al,[num1]

    mov cl,0
    mov edx,0
    mov edx,08h

    addup:
        rcr al,01
        jnc next1
        mov bh,00h
        shl bx,cl
        add [result],bx
        mov bl,[num2]
    next1:     inc cl
               dec edx    
        jnz addup

    display resmsg,resmsg_len
    mov ebx,[result]
    call disp16_proc

display blankmsg,blank_len

exit:    mov rax,60
    mov rbx,00
    syscall

;**********Packnum Procedure**********************
packnum:
    mov bl,0
    mov ecx,02
    mov esi,numascii
    up1:rol bl,04
    mov al,[esi]
    cmp al,39h
    jbe skip1
    sub al,07h
 skip1: sub al,30h
    add bl,al
    inc esi
    loop up1
    ret
;**********Display Procedure**********************
disp16_proc:
    mov ecx,4
    mov edi,dispbuff
 dup1:  rol bx,4
    mov al,bl
    and al,0fh
    cmp al,09
    jbe dskip
    add al,07h
 dskip: add al,30h
        mov [edi],al
        inc edi
        loop dup1
        display dispbuff,4
        ret
;**********Output**********************
;[root@localhost MIT2016]# nasm -f elf64 Ass3B.asm
;[root@localhost MIT2016]# ld -o Ass3B Ass3B.o
;[root@localhost MIT2016]# ./Ass3B

;Multiplication using Add & Shift method

;Enter two digits of Number::04

;Enter two digits of Number::05

;Multiplication of elements::0014

;[root@localhost MIT2016]#
