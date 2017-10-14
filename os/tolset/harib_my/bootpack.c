#include <stdio.h>

extern char hankaku[4096];
void io_hlt(void);
void write_mem8(int, int);
int io_load_eflags(void);
void io_cli(void);
void io_store_eflags(int eflags);
void io_out8(int port, int data);

void init_palette(void);
void set_palette(int, int, char rgb[]);
void hlt_loop(void);
void boxfill8(char *vram, int xsize, unsigned char c, int x0, int y0, int x1, int y1);
void putfont8_asc(char *vram, int xsize, int x, int y, unsigned char c, unsigned char *s);
void putfont8(char *vram, int xsize, int x, int y, unsigned char c,char *font);
void init_screen(char *vram, int x, int y);
void init_mouse_cursor8(char *mouse, char bc);
void putblock8_8(char *vram, int vxsize, int pxsize,
    int pysize, int px0, int py0, char *buf, int bxsize);
void init_gdtidt(void);
void set_segmdesc(struct SEGMENT_DESCRIPTOR *sd, unsigned int limit, int base, int ar);

#define COL8_000000 0  /*  0:黒 */
#define COL8_FF0000 1  /*  1:明るい赤 */
#define COL8_00FF00 2  /*  2:明るい緑 */
#define COL8_FFFF00 3  /*  3:明るい黄色 */
#define COL8_0000FF 4  /*  4:明るい青 */
#define COL8_FF00FF 5  /*  5:明るい紫 */
#define COL8_00FFFF 6  /*  6:明るい水色 */
#define COL8_FFFFFF 7  /*  7:白 */
#define COL8_C6C6C6 8  /*  8:明るい灰色 */
#define COL8_840000 9  /*  9:暗い赤 */
#define COL8_008400 10 /* 10:暗い緑 */
#define COL8_848400 11 /* 11:暗い黄色 */
#define COL8_000084 12 /* 12:暗い青 */
#define COL8_840084 13 /* 13:暗い紫 */
#define COL8_008484 14 /* 14:暗い水色 */
#define COL8_848484 15 /* 15:暗い灰色 */

struct BOOTINFO {
    char cyls, leds, vmode;
    short scrnx, scrny;
    char *vram;
};

struct SEGMENT_DESCRIPTOR {
    short limit_low, base_low;
    char base_mid, access_right;
    char limit_high, base_high;
};

struct GATE_DESCRIPTOR {
    short offset_low,selector;
    char dw_count, access_right;
    short offset_high;
}

void HariMain(void) {
    char *vram;
    struct BOOTINFO *binfo;
    init_palette();
    binfo = (struct BOOTINFO *)0x0ff0;

    char buf[40],mcursor[256];;
    int xsize, ysize,mx,my;
    xsize = binfo->scrnx;
    ysize = binfo->scrny;
    vram = binfo->vram;
    mx = (xsize - 16) / 2;
    my = (ysize - 28 - 16) / 2;

    init_screen(vram, xsize, ysize);
    
    putfont8_asc(binfo->vram, binfo->scrnx, 8, 8, COL8_848400,"ABC 123");
    putfont8_asc(binfo->vram, binfo->scrnx, 8, 24, COL8_848400,"MartinHan");
    sprintf(buf, "scrnx = %d", binfo->scrnx);
    putfont8_asc(binfo->vram, binfo->scrnx, 8, 40, COL8_848400,buf);
    init_mouse_cursor8(mcursor, COL8_008484);
    putblock8_8(binfo->vram, binfo->scrnx, 16, 16, mx, my, mcursor, 16);
    hlt_loop();
}

void init_palette(void) {
    static unsigned char table_rgb[16 * 3] = {
        0x00, 0x00, 0x00, /*  0:黒 */
        0xff, 0x00, 0x00, /*  1:明るい赤 */
        0x00, 0xff, 0x00, /*  2:明るい緑 */
        0xff, 0xff, 0x00, /*  3:明るい黄色 */
        0x00, 0x00, 0xff, /*  4:明るい青 */
        0xff, 0x00, 0xff, /*  5:明るい紫 */
        0x00, 0xff, 0xff, /*  6:明るい水色 */
        0xff, 0xff, 0xff, /*  7:白 */
        0xc6, 0xc6, 0xc6, /*  8:明るい灰色 */
        0x84, 0x00, 0x00, /*  9:暗い赤 */
        0x00, 0x84, 0x00, /* 10:暗い緑 */
        0x84, 0x84, 0x00, /* 11:暗い黄色 */
        0x00, 0x00, 0x84, /* 12:暗い青 */
        0x84, 0x00, 0x84, /* 13:暗い紫 */
        0x00, 0x84, 0x84, /* 14:暗い水色 */
        0x84, 0x84, 0x84  /* 15:暗い灰色 */
    };
    set_palette(0, 15, table_rgb);
    return;
}



void putfont8_asc(char *vram, int xsize, int x, int y, unsigned char c, unsigned char *s) {
    for (; *s != 0x00; s++)
    {
        putfont8(vram, xsize, x, y, c, hankaku + *s * 16);
        x += 8;
    }
    return ;
}

void putfont8(char *vram, int xsize, int x, int y, unsigned char c, char *font)
{
    int i;
    char d;
    for (i = 0; i < 16; i++)
    {
        d = font[i];
        if ((d & 0x80)) { vram[(y + i) * xsize + x + 0] = c;}
        if ((d & 0x40)) { vram[(y + i) * xsize + x + 1] = c;}
        if ((d & 0x20)) { vram[(y + i) * xsize + x + 2] = c;}
        if ((d & 0x10)) { vram[(y + i) * xsize + x + 3] = c;}
        if ((d & 0x08)) { vram[(y + i) * xsize + x + 4] = c;}
        if ((d & 0x04)) { vram[(y + i) * xsize + x + 5] = c;}
        if ((d & 0x02)) { vram[(y + i) * xsize + x + 6] = c;}
        if ((d & 0x01)) { vram[(y + i) * xsize + x + 7] = c;}

    }
}

void init_screen(char *vram, int x, int y) {
    boxfill8(vram, x, COL8_008484, 0, 0, x - 1, y - 29);
    boxfill8(vram, x, COL8_C6C6C6, 0, y - 28, x - 1, y - 28);
    boxfill8(vram, x, COL8_FFFFFF, 0, y - 27, x - 1, y - 27);
    boxfill8(vram, x, COL8_C6C6C6, 0, y - 26, x - 1, y - 1);

    boxfill8(vram, x, COL8_FFFFFF, 3, y - 24, 59, y - 24);
    boxfill8(vram, x, COL8_FFFFFF, 2, y - 24, 2, y - 4);
    boxfill8(vram, x, COL8_848484, 3, y - 4, 59, y - 4);
    boxfill8(vram, x, COL8_848484, 59, y - 23, 59, y - 5);
    boxfill8(vram, x, COL8_000000, 2, y - 3, 59, y - 3);
    boxfill8(vram, x, COL8_000000, 60, y - 24, 60, y - 3);

    boxfill8(vram, x, COL8_848484, x - 47, y - 24, x - 4, y - 24);
    boxfill8(vram, x, COL8_848484, x - 47, y - 23, x - 47, y - 4);
    boxfill8(vram, x, COL8_FFFFFF, x - 47, y - 3, x - 4, y - 3);
    boxfill8(vram, x, COL8_FFFFFF, x - 3, y - 24, x - 3, y - 3);
    return;
}

void set_palette(int start, int end, char rgb[]) {
    int i, eflags;
    eflags = io_load_eflags();
    io_cli();
    io_out8(0x03c8, start);
    for (i = start; i <= end; i++)
    {
        io_out8(0x03c9, rgb[0] / 4);
        io_out8(0x03c9, rgb[1] / 4);
        io_out8(0x03c9, rgb[2] / 4);
        rgb += 3;
    }

    io_store_eflags(eflags);
    return;
}

void boxfill8(char *vram, int xsize, unsigned char c, int x0, int y0, int x1, int y1) {
    int x, y;
    for (x = x0; x <= x1; x++)
    {
        for (y = y0; y < y1; y++)
        {
            vram[x + y * xsize] = c;
        }
    }
}

void hlt_loop(void) {
fin:
    io_hlt();
    goto fin;
}

void init_mouse_cursor8(char *mouse, char bc)
{
	static char cursor[16][16] = {
		"**************..",
		"*OOOOOOOOOOO*...",
		"*OOOOOOOOOO*....",
		"*OOOOOOOOO*.....",
		"*OOOOOOOO*......",
		"*OOOOOOO*.......",
		"*OOOOOOO*.......",
		"*OOOOOOOO*......",
		"*OOOO**OOO*.....",
		"*OOO*..*OOO*....",
		"*OO*....*OOO*...",
		"*O*......*OOO*..",
		"**........*OOO*.",
		"*..........*OOO*",
		"............*OO*",
		".............***"
	};
	int x, y;

	for (y = 0; y < 16; y++) {
		for (x = 0; x < 16; x++) {
			if (cursor[y][x] == '*') {
				mouse[y * 16 + x] = COL8_000000;
			}
			if (cursor[y][x] == 'O') {
				mouse[y * 16 + x] = COL8_FFFFFF;
			}
			if (cursor[y][x] == '.') {
				mouse[y * 16 + x] = bc;
			}
		}
	}
	return;
}

void putblock8_8(char *vram, int vxsize, int pxsize,
	int pysize, int px0, int py0, char *buf, int bxsize)
{
	int x, y;
	for (y = 0; y < pysize; y++) {
		for (x = 0; x < pxsize; x++) {
			vram[(py0 + y) * vxsize + (px0 + x)] = buf[y * bxsize + x];
		}
	}
	return;
}

void init_gdtidt(void) {
    struct SEGMENT_DESCRIPTOR *gdt = (struct SEGMENT_DESCRIPTOR *)0x00270000;
    struct GATE_DESCRIPTOR *idt    = (struct GATE_DESCRIPTOR    *)0x0026f800;
    int i;
    for(i = 0; i < 8192; i++) {
        set_segmdesc(gdt + i, 0, 0, 0);
    }


}

void set_segmdesc(struct SEGMENT_DESCRIPTOR *gd, unsigned int limit, int base, int ar) {
    gd->offset_low   = offset & 0xffff;
    gd->selector     = selector;
    gd->dw_count     = (ar >> 8) & 0xff;
    gd->access_right = ar & 0xff;
    gd->offset_high  = (offset >> 16) & 0xffff;
    return ;
}