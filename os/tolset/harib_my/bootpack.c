#include <stdio.h>
#include "bootpack.h"

void HariMain(void) {
    char *vram;
    struct BOOTINFO *binfo;
    init_gdtidt();
    init_pic();
    io_sti();
    
    init_palette();
    binfo = (struct BOOTINFO *)ADR_BOOTINFO;

    char mcursor[256];;
    int xsize, ysize,mx,my;
    xsize = binfo->scrnx;
    ysize = binfo->scrny;
    vram = binfo->vram;
    mx = (xsize - 16) / 2;
    my = (ysize - 28 - 16) / 2;
    
    init_screen(vram, xsize, ysize);
    
    // putfont8_asc(binfo->vram, binfo->scrnx, 8, 8, COL8_848400,"ABC 123");
    // putfont8_asc(binfo->vram, binfo->scrnx, 8, 24, COL8_848400,"MartinHan");
    // sprintf(buf, "scrnx = %d", binfo->scrnx);
    // putfont8_asc(binfo->vram, binfo->scrnx, 8, 40, COL8_848400,buf);
    init_mouse_cursor8(mcursor, COL8_008484);
    putblock8_8(binfo->vram, binfo->scrnx, 16, 16, mx, my, mcursor, 16);
    
    hlt_loop();
}

void hlt_loop(void) {
fin:
    io_hlt();
    goto fin;
}
