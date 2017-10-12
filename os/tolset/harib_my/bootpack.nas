[FORMAT "WCOFF"]
[INSTRSET "i486p"]
[OPTIMIZE 1]
[OPTION 1]
[BITS 32]
	EXTERN	_io_load_eflags
	EXTERN	_io_cli
	EXTERN	_io_out8
	EXTERN	_io_store_eflags
	EXTERN	_io_hlt
[FILE "bootpack.c"]
[SECTION .text]
	GLOBAL	_HariMain
_HariMain:
	PUSH	EBP
	MOV	EBP,ESP
	CALL	_init_palette
	PUSH	171
	PUSH	319
	PUSH	0
	PUSH	0
	PUSH	14
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	PUSH	172
	PUSH	319
	PUSH	172
	PUSH	0
	PUSH	8
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	ADD	ESP,56
	PUSH	173
	PUSH	319
	PUSH	173
	PUSH	0
	PUSH	7
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	PUSH	199
	PUSH	319
	PUSH	174
	PUSH	0
	PUSH	8
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	ADD	ESP,56
	PUSH	176
	PUSH	59
	PUSH	176
	PUSH	3
	PUSH	7
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	PUSH	196
	PUSH	2
	PUSH	176
	PUSH	2
	PUSH	7
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	ADD	ESP,56
	PUSH	196
	PUSH	59
	PUSH	196
	PUSH	3
	PUSH	15
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	PUSH	195
	PUSH	59
	PUSH	177
	PUSH	59
	PUSH	15
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	ADD	ESP,56
	PUSH	197
	PUSH	59
	PUSH	197
	PUSH	2
	PUSH	0
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	PUSH	197
	PUSH	60
	PUSH	176
	PUSH	60
	PUSH	0
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	ADD	ESP,56
	PUSH	176
	PUSH	316
	PUSH	176
	PUSH	273
	PUSH	15
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	PUSH	196
	PUSH	273
	PUSH	177
	PUSH	273
	PUSH	15
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	ADD	ESP,56
	PUSH	197
	PUSH	316
	PUSH	197
	PUSH	273
	PUSH	7
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	PUSH	197
	PUSH	317
	PUSH	176
	PUSH	317
	PUSH	7
	PUSH	320
	PUSH	655360
	CALL	_boxfill8
	ADD	ESP,56
	LEAVE
	JMP	_hlt_loop
[SECTION .data]
_table_rgb.0:
	DB	0
	DB	0
	DB	0
	DB	-1
	DB	0
	DB	0
	DB	0
	DB	-1
	DB	0
	DB	-1
	DB	-1
	DB	0
	DB	0
	DB	0
	DB	-1
	DB	-1
	DB	0
	DB	-1
	DB	0
	DB	-1
	DB	-1
	DB	-1
	DB	-1
	DB	-1
	DB	-58
	DB	-58
	DB	-58
	DB	-124
	DB	0
	DB	0
	DB	0
	DB	-124
	DB	0
	DB	-124
	DB	-124
	DB	0
	DB	0
	DB	0
	DB	-124
	DB	-124
	DB	0
	DB	-124
	DB	0
	DB	-124
	DB	-124
	DB	-124
	DB	-124
	DB	-124
[SECTION .text]
	GLOBAL	_init_palette
_init_palette:
	PUSH	EBP
	MOV	EBP,ESP
	PUSH	_table_rgb.0
	PUSH	15
	PUSH	0
	CALL	_set_palette
	LEAVE
	RET
	GLOBAL	_set_palette
_set_palette:
	PUSH	EBP
	MOV	EBP,ESP
	PUSH	EDI
	PUSH	ESI
	PUSH	EBX
	PUSH	ECX
	MOV	EBX,DWORD [8+EBP]
	MOV	EDI,DWORD [12+EBP]
	MOV	ESI,DWORD [16+EBP]
	CALL	_io_load_eflags
	MOV	DWORD [-16+EBP],EAX
	CALL	_io_cli
	PUSH	EBX
	PUSH	968
	CALL	_io_out8
	TEST	EDI,EDI
	POP	EAX
	POP	EDX
	JS	L10
	LEA	EBX,DWORD [1+EDI]
L8:
	MOVSX	EAX,BYTE [ESI]
	PUSH	EAX
	PUSH	969
	CALL	_io_out8
	MOVSX	EAX,BYTE [1+ESI]
	PUSH	EAX
	PUSH	969
	CALL	_io_out8
	MOVSX	EAX,BYTE [2+ESI]
	PUSH	EAX
	ADD	ESI,3
	PUSH	969
	CALL	_io_out8
	ADD	ESP,24
	DEC	EBX
	JNE	L8
L10:
	MOV	EAX,DWORD [-16+EBP]
	MOV	DWORD [8+EBP],EAX
	LEA	ESP,DWORD [-12+EBP]
	POP	EBX
	POP	ESI
	POP	EDI
	POP	EBP
	JMP	_io_store_eflags
	GLOBAL	_boxfill8
_boxfill8:
	PUSH	EBP
	MOV	EBP,ESP
	PUSH	EDI
	PUSH	ESI
	PUSH	EBX
	SUB	ESP,12
	MOV	EDI,DWORD [28+EBP]
	MOV	AL,BYTE [16+EBP]
	MOV	EBX,DWORD [20+EBP]
	MOV	ESI,DWORD [32+EBP]
	MOV	BYTE [-13+EBP],AL
	CMP	EBX,EDI
	JG	L23
L21:
	MOV	ECX,DWORD [24+EBP]
	CMP	ECX,ESI
	JGE	L25
	MOV	EDX,DWORD [12+EBP]
	MOV	EAX,DWORD [8+EBP]
	IMUL	EDX,ECX
	ADD	EAX,EBX
	MOV	DWORD [-20+EBP],EAX
	MOV	EAX,EDX
	MOV	EDX,ESI
	ADD	EAX,DWORD [-20+EBP]
	SUB	EDX,ECX
	MOV	ECX,EDX
L20:
	MOV	DL,BYTE [-13+EBP]
	MOV	BYTE [EAX],DL
	ADD	EAX,DWORD [12+EBP]
	DEC	ECX
	JNE	L20
L25:
	INC	EBX
	CMP	EBX,EDI
	JLE	L21
L23:
	ADD	ESP,12
	POP	EBX
	POP	ESI
	POP	EDI
	POP	EBP
	RET
	GLOBAL	_hlt_loop
_hlt_loop:
	PUSH	EBP
	MOV	EBP,ESP
L27:
	CALL	_io_hlt
	JMP	L27
