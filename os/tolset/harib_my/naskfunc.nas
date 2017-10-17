;naskfunc
;TAB=4

[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[BITS 32]

[FILE "naskfunc.nas"]
    GLOBAL      _io_hlt,_write_mem8,_io_load_eflags
    GLOBAL      _io_cli,_io_store_eflags,_io_out8
    GLOBAL      _io_sti
    GLOBAL	    _load_gdtr, _load_idtr
    GLOBAL	    _asm_inthandler21,_asm_inthandler27
    EXTERN      _inthandler21,_inthandler27,_printtest
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

_io_sti:	; void io_sti(void);
		STI
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

_asm_inthandler21:
    PUSH    ES
    PUSH    DS
    PUSHAD
    MOV     EAX,ESP
    PUSH    EAX
    MOV     AX,SS
    MOV     DS,AX
    MOV     ES,AX
    CALL    _inthandler21
    POP     EAX
    POPAD
    POP     DS
    POP     ES
    IRETD
_asm_inthandler21:
		PUSH	ES
		PUSH	DS
		PUSHAD
		MOV		EAX,ESP
		PUSH	EAX
		MOV		AX,SS
		MOV		DS,AX
		MOV		ES,AX
        CALL    _printtest
		CALL	_inthandler21
		POP		EAX
		POPAD
		POP		DS
		POP		ES
		IRETD


_asm_inthandler27:
		PUSH	ES
		PUSH	DS
		PUSHAD
		MOV		EAX,ESP
		PUSH	EAX
		MOV		AX,SS
		MOV		DS,AX
		MOV		ES,AX
        CALL    _printtest
		CALL	_inthandler27
		POP		EAX
		POPAD
		POP		DS
		POP		ES
		IRETD