;Problem Statement:Write 80387 ALP to find the roots of the quadratic equation. All the possible cases must be considered in calculating the roots. 

section .data
msg1 db "Complex Root",10
msglen1 equ $-msg1
msg2 db "Root1: "
msglen2 equ $-msg2
msg3 db "Root2: "
msglen3 equ $-msg3
a dd 1.00
b dd 8.00
c dd 15.00
four dd 4.00
two dd 2.00

hdec dq 100
point db "."
        
section .bss
    
    root1 resd 1
    root2 resd 1
    resbuff rest 1
    temp resb 2
    disc resd 1

%macro write 2            ;macro for display
    mov rax,1 
    mov rdi,1
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

%macro read 2            ;macro for input
    mov rax,0
    mov rdi,0
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

%macro exit 0            ;macro for exit
    mov rax,60
    xor rdi,rdi
    syscall
%endmacro

section .text
  global _start
  _start:
  
  finit                ; initialise 80387 co-processor
  fld dword[b]            ; stack: b

    
     
  fmul dword[b]             ; stack: b*b

  fld dword[a]            ; stack: a, b*b

  fmul dword[c]             ; stack: a*c, b*b

  fmul dword[four]        ; stack: 4*a*c,b*b
  
  fsub                 ; stack: b*b - 4*a*c

  ftst                 ; compares ST0 and 0
   
   
  fstsw ax                ;Stores the coprocessor status word ;into either a word in memory or the AX register
  sahf        ;Stores the AH register into the FLAGS register.
  jb no_real_solutions         ; if disc < 0, no real solutions
  fsqrt             ; stack: sqrt(b*b - 4*a*c)

  fst dword[disc]     ; store disc= sqrt(b*b - 4*a*c)

  fsub dword[b]                 ; stack: disc-b

  fdiv dword[a]             ; stack: disc-b/2*a or (-b+disc)/2a


  fdiv dword[two]

  write msg2,msglen2  
 call disp_proc 
  fldz                ;stack:0
  fsub dword[disc]        ;stack:-disc
  fsub dword[b]             ; stack: -disc - b
  fdiv dword[a]        ; stack: (-b - disc)/(2*a)
  fdiv dword[two]
  
  write msg3,msglen3
  call disp_proc 
  jmp exi

no_real_solutions:
write msg1,msglen1
exi : 

mov rax,60
mov rdi,1
syscall
      

disp_proc:
    FIMUL dword[hdec]
    FBSTP tword[resbuff]
    mov rsi,resbuff+9
    mov rcx,09
  next1:
      
      push rcx
      push rsi
      
      mov bl,[rsi]
      call disp
      
      pop rsi
      pop rcx
      
       dec rsi
      loop next1
    push rsi
      write point,1
    pop rsi
      mov bl,[rsi]
      call disp
    ret
  

disp:
        mov edi,temp                ;mov dnum address into edi
        mov ecx,02                    ;initialize ecx with 2
        dispup1:
            rol bl,4                ;rotate bl by 4 bits
            mov dl,bl                ;move bl into dl
            and dl,0fh            ;and of dl with 0fh
            add dl,30h            ;add 30h into dl
            cmp dl,39h            ;compare dl with 39h
            jbe dispskip1            ;jump if below and equal to dispskip1
            add dl,07h            ;add 7h into dl
            dispskip1:
                mov [edi],dl        ;mov dl into dnum
                inc edi            ;increament edi by a byte
            loop dispup1        ;loop dispup1 while ecx not zero
            write temp,2            ;Display dnum by calling macro
          ret                    ;return from procedure
