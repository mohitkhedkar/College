;Problem Statement: Write X86/64 ALP to switch from real mode to protected mode and display the values of GDTR, LDTR, IDTR, TR and MSW Registers.  

;*****************************************************
section .data
rmodemsg db 10,"Processor is in Real Mode"
rmsg_len equ $-rmodemsg

pmodemsg db 10,"Processor is in Protected Mode"
pmsg_len equ $-pmodemsg

gdtmsg db 10,"GDT Contents are::"
gdtmsg_len equ $-gdtmsg

ldtmsg db 10,"LDT Contents are::"
ldtmsg_len equ $-ldtmsg

idtmsg db 10,"IDT Contents are::"
idtmsg_len equ $-idtmsg

trmsg db 10,"Task Register Contents are::"
trmsg_len equ $-trmsg

mswmsg db 10,"Machine Status Word::"
mswmsg_len equ $-mswmsg

colmsg db ":"

nwline db 10
;************************************************************
section .bss

gdt resd 1
resw 1
ldt resw 1
idt resd 1
resw 1
tr  resw 1

cr0_data resd 1

dispbuff resb 04

%macro display 2
    mov    rax,1    ;print
    mov    rdi,1    ;stdout/screen
    mov    rsi,%1    ;msg
    mov    rdx,%2    ;msg_len
    syscall
%endmacro

;*******************************************************
section .text
global _start
_start:
    smsw eax    ;Stores the machine status word (bits 0 
                ;through   15 of control register CR0) into eax.

    mov [cr0_data],eax

    bt eax,0    ;Checking PE(Protected Mode Enable) bit(LSB), 
                ;if 1=Protected Mode, else Real Mode 
    jc prmode
    display rmodemsg,rmsg_len
    jmp nxt1

prmode: display pmodemsg,pmsg_len

nxt1:sgdt [gdt]    
     sldt [ldt]         
     sidt [idt]  
     str [tr]   
    ;.......display gdt data...........

     display gdtmsg,gdtmsg_len

     mov bx,[gdt+4]
     call display16_proc

     mov bx,[gdt+2]
     call display16_proc

     display colmsg,1

     mov bx,[gdt]
     call display16_proc
   
    ;......display ldt data...........
     
     display ldtmsg,ldtmsg_len
     mov bx,[ldt]
     call display16_proc

    ;......display idt data...........

    display idtmsg,idtmsg_len

    mov bx,[idt+4]
    call display16_proc

    mov bx,[idt+2]
    call display16_proc

    display colmsg,1

    mov bx,[idt]
    call display16_proc

    ;....display task register data..........

    display trmsg,trmsg_len

    mov bx,[tr]
    call display16_proc

    ;....display machine status word data......

    display mswmsg,mswmsg_len

    mov bx,[cr0_data+2]
    call display16_proc

    mov bx,[cr0_data]
    call display16_proc

    display nwline,1

    mov rax,60
    mov rdi,0
    syscall
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
