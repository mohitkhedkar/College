;Write X86 program to sort the list of integers in ;ascending/descending order.
;Read the input from the text file and write the sorted data back ;to the same text file  using bubble sort


section .data
 fname db 'a.txt',0

 msg1 db 'File opened Sucessfully',0xa
 len1 equ $-msg1
 msg2 db 'Error in opening File ',0xa
 len2 equ $-msg2
 msg3 db 'Sorted array is:',0xa
 len3 equ $-msg3

section .bss
 fd_in resb 8
 buffer resb 200
 buff_len resb 8

 count1 resb 8
 count2 resb 8

section .text

global _start
_start:

 xor rax,rax
 xor rbx,rbx
 xor rcx,rcx

 mov rax,2
 mov rdi,fname
 mov rsi,2
 mov rdx,0777
 syscall

 mov qword[fd_in],rax
 bt rax,63
 jc next

 mov rax,1
 mov rdi,1 
 mov rsi,msg1
 mov rdx,len1
 syscall

 jmp next2

next:
 mov rax,1
 mov rdi,1
 mov rsi,msg2
 mov rdx,len2
 syscall

next2:
 mov rax,0
 mov rdi,[fd_in]
 mov rsi,buffer
 mov rdx,200
 syscall

 mov qword[buff_len],rax

 mov qword[buff_len],rax ;for rounds
 mov qword[count1],rax
  mov qword[count2],rax


bubble:
 mov al,byte[count2]
 mov byte[count1],al
 dec byte[count1]

 mov rsi,buffer
 mov rdi,buffer+1

loop:
 mov bl,byte[rsi]
 mov cl,byte[rdi]
  cmp bl,cl
  ja swap
  inc rsi
  inc rdi
  dec byte[count1]
  jnz loop
 dec byte[buff_len]
 jnz bubble
 jmp end
swap:
  
  mov byte[rsi],cl
  mov byte[rdi],bl
  inc rsi
  inc rdi
  dec byte[count1]
  jnz loop
 dec byte[buff_len]
 jnz bubble

end:
 mov rax,1
 mov rdi,1
 mov rsi,msg3
 mov rdx,len3
 syscall

 mov rax,1
 mov rdi,1
 mov rsi,buffer
 mov rdx,qword[count2]
 syscall


 mov rax,1
 mov rdi,qword[fd_in]
 mov rsi,msg3
 mov rdx,len3
 syscall

 mov rax,1
 mov rdi,qword[fd_in]
 mov rsi,buffer
 mov rdx,qword[count2]
 syscall

 mov rax,3
 mov rdi,fname
  syscall


 mov rax,60
 mov rdi,0
 syscall

