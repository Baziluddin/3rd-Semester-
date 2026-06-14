INCLUDE Irvine32.inc

.data
num1 WORD 500
num2 WORD 200

.code
main PROC

    mov ax, num1
    mov bx, num2

    add eax, ax
    add eax, bx

    call DumpRegs

    exit
main ENDP
END main
