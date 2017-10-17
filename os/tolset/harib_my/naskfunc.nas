;naskfunc
;TAB=4

[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[BITS 32]

[FILE "naskfunc.nas"]
    GLOBAL      _io_hlt,_write_mem8,_io_load_eflags
    GLOBAL      _io_cli,_io_store_eflags,_io_out8
    GLOBAL	    _load_gdtr, _load_idtr
[SECTION .text]
_io_hlt:    ;void io_hlt()
    HLT
    RET

_write_mem8:    ;void write_mem8(int addr, int data)
    MOV     ECX,[ESP + 4]
    MOV     AL,[ESP + 8]
    MOV     [ECX],AL
    RET

_io_load_eflags:  ;int io_load_eflags()
    PUSHFD
    POP     EAX
    RET

_io_cli:    ;void io_cli()
    CLI
    RET

_io_store_eflags:   ;void io_store_eflags(int)
    MOV     EAX,[ESP + 4]
    PUSH    EAX
    POPFD
    RET
_io_out8:    ;io_out8(int port,int data)
    MOV		EDX,[ESP+4]		; port
    MOV		AL,[ESP+8]		; data
    OUT		DX,AL
    RET
_load_gdtr:   ;void _load_gdtr(int limit, int addr)
    MOV     AX,[ESP + 4]
    MOV     [ESP + 6],AX
    LGDT    [ESP + 6]
    RET
_load_idtr:   ;void _load_idtr(int limit, int addr)
    MOV     AX, [ESP +4]
    MOV     [ESP + 6],AX
    LIDT    [ESP + 6]
    RET