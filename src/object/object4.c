#include "global.h"
#include "entity.h"
#include "player.h"

extern bool32 sub_080AE008(Entity*, int, int);
extern void sub_08082098(Entity*);

extern void (*const gUnk_0811EE5C[])(Entity*);

void Object4(Entity* this) {
    gUnk_0811EE5C[this->action](this);
}

void sub_08082058(Entity* this) {
    this->scriptedScene = 6;
    this->flags |= 0x20;
    this->spriteSettings.b.draw = 1;
    this->action = 1;
    sub_080AE008(this, 1, 3);
    sub_08082098(this);
}

extern void sub_08079BD8(Entity*);

void sub_08082098(Entity* this) {
    register u32 var0 asm("r3");
    register u32 var1 asm("r7");
    register u32 var2 asm("r6");
    Entity* player;
    u32 var4;

    if (!(gPlayerState.flags.all & 0x80)) {
        DeleteThisEntity();
    }

    player = &gPlayerEntity;
    sub_08079BD8(this);
    this->spriteOrientation.flipY = 1;
    this->palette.b.b0 = player->palette.b.b0;
    this->animationState = player->animationState & 0xE;
    this->spritePriority.b0 = 0;
    var0 = player->animationState / 2;
    var1 = var0;
    switch (player->action) {
        case 22:
            var4 = this->animationState;
            var0 = 13;
            if (var4 == 2) {
                var0 = 14;
            }
            break;
        case 20:
            var0 = 12;
            break;
        case 24:
            var0 += 15;
            break;
        case 10:
            var0 = 19;
            break;
        default:
            if (player->field_0x42) {
                var0 = var1 + 8;
            } else {
                var2 = gPlayerState.jumpStatus;
                if (var2) {
                    if (!(gPlayerState.jumpStatus & 0x10)) {
                        var0 = var1 + 25;
                    }
                } else if (gPlayerState.field_0xa8[0] == 1 || gPlayerState.field_0xa8[0] == 25) {
                    var0 = var1 + 4;
                    if (this->animIndex != var0) {
                        this->height.WORD = var2;
                        this->actionDelay = 6;
                    } else {
                        this->actionDelay--;
                        var1 = 0xFF;
                        if (this->actionDelay == 0xFF) {
                            switch ((s8)this->spriteOffsetY) {
                                case 0:
                                    this->spriteOffsetY = -2;
                                    this->actionDelay = 6;
                                    break;
                                case -2:
                                    this->spriteOffsetY |= var1;
                                    this->actionDelay = 6;
                                    break;
                                case -1:
                                    this->spriteOffsetY = var2;
                                    this->actionDelay = 3;
                                    break;
                            }
                        }
                    }
                } else if (gPlayerState.swimState) {
                    var4 = gPlayerState.swimState & 0x80;
                    var0 = var1 + 20;
                    if (var4) {
                        var0 = 24;
                    }
                } else {
                    this->spriteOffsetY = 0;
                }
            }
            break;
    }

    if (this->animIndex != var0) {
        InitAnimationForceUpdate(this, var0);
    } else {
        UpdateAnimationSingleFrame(this);
    }
}
