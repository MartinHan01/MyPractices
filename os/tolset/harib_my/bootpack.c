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
void putfont8(char *vram, int xsize, int x, int y, char c, char *font);
void init_screen(char *vram, int x, int y);

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

struct BOOTINFO
{
    char cyls, leds, vmode;
    short scrnx, scrny;
    char *vram;
};

void HariMain(void)
{
    char *vram;
    struct BOOTINFO *binfo;
    init_palette();
    binfo = (struct BOOTINFO *)0x0ff0;

    int xsize, ysize;
    xsize = binfo->scrnx;
    ysize = binfo->scrny;
    vram = binfo->vram;

    init_screen(vram, xsize, ysize);

    static char font_A[16] = {
        0x00, 0x18, 0x18, 0x18, 0x18, 0x24, 0x24, 0x24,
        0x24, 0x7e, 0x42, 0x42, 0x42, 0xe7, 0x00, 0x00};

    putfont8(binfo->vram, binfo->scrnx, 0, 0, COL8_840084, font_A);

    hlt_loop();
}

void init_palette(void)
{
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

void putfont8(char *vram, int xsize, int x, int y, char c, char *font)
{
    int i;
    char d;
    for (i = 0; i < 16; i++)
    {
        d = font[i];
        if ((d & 0x80))
        {
            vram[(y + i) * xsize + x + 0] = c;
        }
        if ((d & 0x40))
        {
            vram[(y + i) * xsize + x + 1] = c;
        }
        if ((d & 0x20))
        {
            vram[(y + i) * xsize + x + 2] = c;
        }
        if ((d & 0x10))
        {
            vram[(y + i) * xsize + x + 3] = c;
        }
        if ((d & 0x08))
        {
            vram[(y + i) * xsize + x + 4] = c;
        }
        if ((d & 0x04))
        {
            vram[(y + i) * xsize + x + 5] = c;
        }
        if ((d & 0x02))
        {
            vram[(y + i) * xsize + x + 6] = c;
        }
        if ((d & 0x01))
        {
            vram[(y + i) * xsize + x + 7] = c;
        }
    }
}

void init_screen(char *vram, int x, int y)
{
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

void set_palette(int start, int end, char rgb[])
{
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

void boxfill8(char *vram, int xsize, unsigned char c, int x0, int y0, int x1, int y1)
{
    int x, y;
    for (x = x0; x <= x1; x++)
    {
        for (y = y0; y < y1; y++)
        {
            vram[x + y * xsize] = c;
        }
    }
}

void hlt_loop(void)
{
fin:
    io_hlt();
    goto fin;
}
