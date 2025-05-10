[BITS 16]
[ORG 0x7C00]

    mov ax, 0x9000
    mov es, ax
    mov bx, 0x0000

    ; Load kernel from disk
    mov ah, 0x02
    mov al, 1
    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov dl, 0x80
    int 0x13

    ; Jump to kernel
    jmp 0x9000:0x0000

    ; Fill bootsector with zeros
    times 510-($-$$) db 0
    dw 0xAA55  ; Boot signature
