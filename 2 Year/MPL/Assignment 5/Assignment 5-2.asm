;Problem Statement:Write X86 ALP to find, a) Number of Blank spaces b) Number of lines c) Occurrence of a particular character. Accept the data from the text file. The text file has to be accessed during Program_1 execution and write FAR PROCEDURES in Program_2 for the rest of the processing. Use of PUBLIC and EXTERN directives is mandatory. 


;************************************************************
global    far_proc       

extern    filehandle, char, buf, abuf_len

%include "macro.asm"
;************************************************************
section .data
    nline        db    10,10
    nline_len:    equ    $-nline

    smsg        db    10,"No. of spaces are    : "
    smsg_len:    equ    $-smsg
    
    nmsg        db    10,"No. of lines are    : "
    nmsg_len:    equ    $-nmsg

    cmsg        db    10,"No. of character occurances are    : "
    cmsg_len:    equ    $-cmsg


;************************************************************
section .bss

    scount    resq    1
    ncount    resq    1
    ccount    resq    1

    dispbuff    resb    4

;************************************************************
section .text
;    global    _main
;_main:

far_proc:                  ;FAR Procedure
    
        mov    rax,0
        mov    rbx,0
        mov    rcx,0
        mov    rsi,0   

        mov    bl,[char]
        mov    rsi,buf
        mov    rcx,[abuf_len]

again:    mov    al,[rsi]

case_s:    cmp    al,20h        ;space : 32 (20H)
        jne    case_n
        inc    qword[scount]
        jmp    next

case_n:    cmp    al,0Ah        ;newline : 10(0AH)
        jne    case_c
        inc    qword[ncount]
        jmp    next

case_c:    cmp    al,bl            ;character
        jne    next
        inc    qword[ccount]

next:        inc    rsi
        dec    rcx            ;
        jnz    again            ;loop again

        display smsg,smsg_len
        mov    rbx,[scount]
        call    display16_proc
    
        display nmsg,nmsg_len
        mov    rbx,[ncount]
        call    display16_proc

        display cmsg,cmsg_len
        mov    rbx,[ccount]
        call     display16_proc

    fclose    [filehandle]
    ret


;************************************************************
display16_proc:
    mov rdi,dispbuff    ;point esi to buffer
    mov rcx,4        ;load number of digits to display 
dispup1:
    rol bx,4        ;rotate number left by four bits
    mov dl,bl        ;move lower byte in dl
    and dl,0fh        ;mask upper digit of byte in dl
    add dl,30h        ;add 30h to calculate ASCII code
    cmp dl,39h        ;compare with 39h
    jbe dispskip1        ;if less than 39h akip adding 07 more 
    add dl,07h        ;else add 07

dispskip1:
    mov [rdi],dl        ;store ASCII code in buffer
    inc rdi            ;point to next byte
    loop dispup1        ;decrement the count of digits to display
                ;if not zero jump to repeat

    display dispbuff,4    ;
    
    ret
;************************************************************

