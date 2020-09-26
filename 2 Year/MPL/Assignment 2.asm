;Write X86/64 ALP to perform non-overlapped and overlapped block transfer (with and without string
;specific instructions). Block containing data can be defined in the data segment.

%macro scall 4                                      ;macro to take input and output
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
        syscall
%endmacro

section .data

menu db 10d,13d,"                   MENU"
     db 10d,"1. Non-Overlapping (Without String Instructions)"
     db 10d,"2. Overlapping (Without String Instructions)"
     db 10d,"3. Non-Overlapping (With String Instructions)"
     db 10d,"4. Overlapping (With String Instructions)"
     db 10d,"5. Exit"
     db 10d
     db 10d,"Enter your choice: "
lnmenu equ $-menu    
 
        m1 db 10d,13d,"Enter Count Of numbers: "
        l1 equ $-m1
        m2 db 10d,13d,"Enter Numbers: ",10d,13d
        l2 equ $-m2
        m3 db 10d,13d,"Array 1: ",10d,13d
        l3 equ $-m3
        m4 db 10d,13d,"Array 2: ",10d,13d
        l4 equ $-m4
        m5 db 10d,13d,"Enter Overlapping Position: "
	l5 equ $-m5
        nwline db 10d,13d
        
section .bss
        choice resb 2
        answer resb 20
        array1 resb 300
	array2 resb 300
	count resb 20
	count1 resb 20
	count2 resb 20
	temp resb 20
	posn resb 20
        
section .text
        global _start
        _start:
        
;**********************MAIN LOGIC****************************
main:        
        scall 1,1,menu,lnmenu
        scall 0,0,choice,2
        
        cmp byte[choice],'5'
        je exit
        
        call inputarray
        
        mov rax,qword[count1]
	mov qword[count],rax
	mov qword[count2],rax
	
        cmp byte[choice],'1'
        je case1
        cmp byte[choice],'2'
        je case2
        cmp byte[choice],'3'
        je case3
        cmp byte[choice],'4'
        je case4
        
        
back:
        mov rax,qword[count2]
	mov qword[count],rax
	
        call displayarray 
        jmp main

;******************CASE1 to CASE4******************************        
case1:          
;number moving from arr1 to arr2
	mov rsi,array1
	mov rdi,array2

loop6:	mov rax,[rsi]
	mov [rdi],rax	
	
	add rsi,8
	add rdi,8
	dec qword[count]
	jnz loop6
        
jmp back
    
case2:
;position enter
	scall 1,1,m5,l5
	scall 0,0,temp,17
	call asciihextohex
	
	mov qword[posn],rbx
	add qword[count1],rbx
	
;number moving from arr1 to arr2
	mov rsi,array1
	mov rdi,array2
	
loop7:	mov rax,[rsi]
	mov [rdi],rax	
	
	add rsi,8
	add rdi,8
	dec qword[count]
	jnz loop7

	mov rax,qword[count2]
	mov qword[count],rax
	
	mov rsi,array1
	mov rdi,array2
	
loop8:	add rdi,8
	dec qword[posn]
	jnz loop8
	
loop9:	mov rax,[rsi]
	mov [rdi],rax	
	
	add rsi,8
	add rdi,8
	dec qword[count]
	jnz loop9
jmp back
    
case3:
        mov rsi,array1
	mov rdi,array2
	
	mov rcx,[count]
	cld                     ;CLEAR DIRECTION FLAG
	rep movsq
        
jmp back
    
case4:  
;position enter
	scall 1,1,m5,l5
	scall 0,0,temp,17
	call asciihextohex
	
	mov qword[posn],rbx
	add qword[count1],rbx
	
;number moving from arr1 to arr2
	mov rsi,array1
	mov rdi,array2
	
	mov rcx,[count]
	cld                     ;CLEAR DIRECTION FLAG
	rep movsq
	
	mov rax,qword[count2]
	mov qword[count],rax
	
	mov rsi,array1
	mov rdi,array2
	
loop10:	add rdi,8
	dec qword[posn]
	jnz loop10
		
	mov rcx,qword[count1]	
	rep movsq
jmp back
           	
exit:                                   ;exit code
	mov rax,60
	mov rdi,0
	syscall

	
;*********************PROCEDURES**********************************

inputarray:
	scall 1,1,m1,l1
	scall 0,0,temp,17
	call asciihextohex
	
        mov qword[count],rbx
        mov qword[count1],rbx
	
	scall 1,1,m2,l2
	mov rbp,array1
	
loop1:	scall 0,0,temp,17
	call asciihextohex
	mov qword[rbp],rbx
	
	add rbp,8
	dec qword[count]
	jnz loop1      
ret

displayarray:
        scall 1,1,m3,l3
	mov rbp,array1
loop2:  mov rax,[rbp]
	call display
	scall 1,1,nwline,1
	add rbp,8
	dec qword[count]
	jnz loop2
	
	mov rax,qword[count1]
	mov qword[count],rax
	
	scall 1,1,m4,l4
	mov rbp,array2
loop3:  mov rax,[rbp]
	call display
	scall 1,1,nwline,1
	add rbp,8
	dec qword[count]
	jnz loop3

ret

asciihextohex:
	mov rsi,temp
	mov rcx,16
	mov rbx,0
	mov rax,0
	
	
loop4:	rol rbx,04
	mov al,[rsi]
	cmp al,39h
	jbe skip1
	sub al,07h
skip1:	sub al,30h
	
	add rbx,rax
	
	inc rsi
	dec rcx
	jnz loop4
ret	

display:
        mov rsi,answer+15
        mov rcx,16

loop5:	mov rdx,0
        mov rbx,16
        div rbx
        cmp dl,09h
        jbe skip2
        
        add dl,07h
skip2:	add dl,30h
        mov [rsi],dl
        
        dec rsi
        dec rcx
        jnz loop5
        scall 1,1,answer,16      
ret