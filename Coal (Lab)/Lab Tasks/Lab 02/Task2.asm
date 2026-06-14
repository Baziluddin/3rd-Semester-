INCLUDE Irvine32.inc

.data
message BYTE "Hello World ",0

.code
main PROC

    mov edx, OFFSET message
    call WriteString
    call Crlf

    exit
main ENDP
END main
