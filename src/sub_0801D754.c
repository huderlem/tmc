#include "global.h"

extern u8 gUnk_020176E0;

extern void sub_0807C960();
extern u32 sub_0801D754(const u8*, u8, u8);

u32 sub_0807C9D8(u32* a1) {
    u32* v1; // r5@1

    v1 = a1;
    sub_0807C960(0x6004000, *a1);
    sub_0807C960(0x6000000, v1[1]);
    sub_0807C960(0x6008000, v1[2]);
    sub_0807C960(&gUnk_020176E0, v1[3]);
    return sub_0801D754(&gUnk_020176E0, 2, 13);
}
