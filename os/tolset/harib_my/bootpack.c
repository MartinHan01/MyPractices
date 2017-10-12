void io_hlt(void);

void write_mem8(int,int);
int io_load_eflags(void);
void io_cli(void);
void io_store_eflags(int eflags);
void io_out8(int port,int data);

void init_palette(void);
void set_palette(int, int, char rgb[]);
void hlt_loop(void);
void boxfill(char* vram, int xsize, unsigned char c, int x0, int y0, int x1, int y1);

#define COL8_000000		0     /*  0:黒 */
#define COL8_FF0000		1     /*  1:明るい赤 */
#define COL8_00FF00		2     /*  2:明るい緑 */
#define COL8_FFFF00		3     /*  3:明るい黄色 */
#define COL8_0000FF		4     /*  4:明るい青 */
#define COL8_FF00FF		5     /*  5:明るい紫 */
#define COL8_00FFFF		6     /*  6:明るい水色 */
#define COL8_FFFFFF		7     /*  7:白 */
#define COL8_C6C6C6		8     /*  8:明るい灰色 */
#define COL8_840000		9     /*  9:暗い赤 */
#define COL8_008400		10    /* 10:暗い緑 */
#define COL8_848400		11    /* 11:暗い黄色 */
#define COL8_000084		12    /* 12:暗い青 */
#define COL8_840084		13    /* 13:暗い紫 */
#define COL8_008484		14    /* 14:暗い水色 */
#define COL8_848484		15    /* 15:暗い灰色 */

void HariMain(void) {
    int i = 0;
    char *p = (char*)0xa0000;
    init_palette();

    boxfill(p, 320, COL8_FF0000, 20, 20, 120, 120);

    
    hlt_loop();
}

void init_palette(void) {
    static unsigned char table_rgb[16 * 3] = {
		0x00, 0x00, 0x00,	/*  0:黒 */
		0xff, 0x00, 0x00,	/*  1:明るい赤 */
		0x00, 0xff, 0x00,	/*  2:明るい緑 */
		0xff, 0xff, 0x00,	/*  3:明るい黄色 */
		0x00, 0x00, 0xff,	/*  4:明るい青 */
		0xff, 0x00, 0xff,	/*  5:明るい紫 */
		0x00, 0xff, 0xff,	/*  6:明るい水色 */
		0xff, 0xff, 0xff,	/*  7:白 */
		0xc6, 0xc6, 0xc6,	/*  8:明るい灰色 */
		0x84, 0x00, 0x00,	/*  9:暗い赤 */
		0x00, 0x84, 0x00,	/* 10:暗い緑 */
		0x84, 0x84, 0x00,	/* 11:暗い黄色 */
		0x00, 0x00, 0x84,	/* 12:暗い青 */
		0x84, 0x00, 0x84,	/* 13:暗い紫 */
		0x00, 0x84, 0x84,	/* 14:暗い水色 */
		0x84, 0x84, 0x84	/* 15:暗い灰色 */
    };
    set_palette(0, 15, table_rgb);
    return ;

}

void set_palette(int start, int end,char rgb[]) {
    int i, eflags;
    eflags = io_load_eflags();
    io_cli();
    io_out8(0x03c8, start);
    for(i = 0; i <= end; i++) {
        io_out8(0x03c9, rgb[0]);
        io_out8(0x03c9, rgb[1]);
        io_out8(0x03c9, rgb[2]);
        rgb += 3;
    }


    io_store_eflags(eflags);
    return ;
}

void boxfill(char* vram, int xsize, unsigned char c, int x0, int y0, int x1, int y1) {
    int x,y;
    for(x = x0; x <= x1; x++) {
        for(y = y0; y < y1; y++) {
            vram[x + y * xsize] = c;
        }
    }
}

void hlt_loop(void) {
    fin:
        io_hlt();
    goto fin;
}
