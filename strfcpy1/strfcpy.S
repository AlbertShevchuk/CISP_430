.global strfcpy
oldebp = 0
retaddr = oldebp + 4
dest = oldebp + 8
src = oldebp + 12
allow = oldebp + 16
oldDest = oldebp - 4
strfcpy:

pushl %ebp
movl %esp,%ebp
movl oldDest(%ebp),%eax
movl src(%ebp), %ecx
movl (%ecx),%ecx

loop:
cmp $0,%cl
jz endLoop
push %ecx
pushl allow(%ebp)
call strchr
jc If 
add $1,src
jmp loop
If:
movb %cl,dest(%ebp)
add $1,dest
add $1,src
jmp loop

endLoop:
movl $0, dest(%ebp)
movl %ebp,%esp
popl %ebp
ret
