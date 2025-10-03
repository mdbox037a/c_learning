bitcount:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-20], edi
        mov     DWORD PTR [rbp-4], 0
        jmp     .L2
.L4:
        mov     eax, DWORD PTR [rbp-20]
        and     eax, 1
        test    eax, eax
        je      .L3
        add     DWORD PTR [rbp-4], 1
.L3:
        shr     DWORD PTR [rbp-20]
.L2:
        cmp     DWORD PTR [rbp-20], 0
        jne     .L4
        mov     eax, DWORD PTR [rbp-4]
        pop     rbp
        ret
faster_bitcount:
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-20], edi
        mov     DWORD PTR [rbp-4], 0
        jmp     .L7
.L8:
        add     DWORD PTR [rbp-4], 1
        mov     eax, DWORD PTR [rbp-20]
        sub     eax, 1
        and     DWORD PTR [rbp-20], eax
.L7:
        cmp     DWORD PTR [rbp-20], 0
        jne     .L8
        mov     eax, DWORD PTR [rbp-4]
        pop     rbp
        ret
