extern char hankaku[4096];
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
};

void io_hlt(void);
void write_mem8(int, int);
int io_load_eflags(void);
void io_cli(void);
void io_store_eflags(int eflags);
void io_out8(int port, int data);
void load_gdtr(int limit, int addr);
void load_idtr(int limit, int addr);


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
void set_gatedesc(struct GATE_DESCRIPTOR *gd, int offset, int selector, int ar);


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