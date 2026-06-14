INCLUDE Irvine32.inc

.code
main PROC

    mov ebx, 90
    mov ebx, 05Ah
    mov ebx, 0b01011010
    mov ebx, 'B'

    call DumpRegs

    exit
main ENDP
END main
