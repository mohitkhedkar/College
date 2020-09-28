;Write a Terminate but Stay Resident (TSR) program for a key-logger. The key-presses during the stipulated time need to be displayed at the center of the screen.  ORWrite  a  TSR  to  generate  the  pattern  of  the  frequency  tones  by  reading  the  Real  Time         Clock (RTC). The duration of the each tone is solely decided by the programmer.
 
 .model tiny

 .code

 ORG 0100h
 start:


	 jmp trans        ;//to go to  initialization

	 intvect dd ?
	 temp db 00h
	 hr db ?
	 min db ?
	 sec db ?
 resi:
	;//to push all  registers
	push ax
	push bx
	push cx
	push dx

	push si
	push di
	push sp
	push bp

	push ss
	push ds
	push es

	mov ah,02h	;To Get System Clock
	int 1Ah

	mov cs:hr,ch     ; ch=hours
	mov cs:min,cl	 ; cl=minutes
	mov cs:sec,dh    ; dh= seconds

	inc cs:temp      ; increment temp

	mov ax,0B800h	 ;Address of Video RAM it is fix value
	mov es,ax       
	mov di,0100

        ; print hours

	mov al,cs:hr   
	and al,0F0h
	mov cl,04h
	shr al,cl
	add al,30h
	mov es:[di],al
	inc di
	inc di

	mov al,cs:hr
	and al,0Fh
	add al,30h
	mov es:[di],al
	inc di
	inc di

	mov al,':'
	mov es:[di],al

	inc di
	inc di

	mov al,cs:min
	and al,0F0h
	mov cl,04h
	shr al,cl
	add al,30h
	mov es:[di],al
	inc di
	inc di

	mov al,cs:min
	and al,0Fh
	add al,30h
	mov es:[di],al
	inc di
	inc di

	mov al,':'
	mov es:[di],al
	inc di
	inc di

	mov al,cs:sec
	and al,0F0h
	mov cl,04h
	shr al,cl
	add al,30h
	mov es:[di],al
	inc di
	inc di

	mov al,cs:sec
	and al,0Fh
	add al,30h
	mov es:[di],al

        cmp cs:temp,60        ; it gives occurance of beep tone
         jne nobeep

	mov cs:temp,00h


        mov     al, 182         ; Prepare the Internal speaker for the note sets up the speaker
        out     43h, al         ;
        mov     ax, 8126        ; Frequency number (in decimal) Actual 130.81
                                ;  for D.
        out     42h, al         ; Output low byte. since it is 8 bit port COUNT register
        mov     al, ah          ; Output high byte.
        out     42h, al
        in      al, 61h         ; Turn on note (get value from
                                ;  port 61h).
        or      al, 00000011b   ; Set bits 1 and 0 to 1
        out     61h, al         ; Send new value.
        mov     bx, 100          ; duration of note (in hundreds of seconds) for beep sound

pause1:
        mov     cx, 9999       ; frequency tone number (intesity of sound) (upto 65535)
pause2:
        dec     cx
        jnz     pause2
        dec     bx
        jnz     pause1
        in      al, 61h         ; Turn off note beep (get value from
                                ;  port 61h).
        and     al, 11111100b   ; Reset bits 1 and 0.
        out     61h, al 


nobeep:	pop es
	pop ds
	pop ss

	pop bp
	pop sp
	pop di
	pop si

	pop dx
	pop cx
	pop bx
	pop ax



	jmp dword ptr cs:intvect



 trans:
	cli
       
	;Get Interrupt vector Data and

	mov ah,35h
	mov al,08h		;//to get address of type 8
	int 21h			;interrupt i.e.timer interrupt

	mov word ptr intvect,bx
	mov word ptr intvect+2,es

	;Set Interrupt vector Data and
	;//repalce old ivt address with new in DX
	mov ah,25h
	mov al,08h
	mov dx,offset resi
	int 21h


	;Make program Transient
	mov ah,31h
	mov al,00h
	mov dx,offset trans
	sti
	int 21h

 end start