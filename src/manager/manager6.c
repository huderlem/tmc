#include "global.h"
#include "entity.h"
#include "link.h"
#include "manager.h"

extern void* GetCurrentRoomProperty(u8);
extern u32 CheckPlayerInRegion(u16, u16, u8, u8);
extern void DoExitTransition(void*);
extern void sub_0805E900(Entity*);

void sub_08057CB4(Entity * this) {
    u32 tmp;
    UnkManagerHelperStruct* i;
    if (this->action == 0){
        this->action = 1;
        this->field_0x20 = (s32) GetCurrentRoomProperty(this->entityType.form);
        if (this->field_0x20 == 0) {
            sub_0805E900(this);
            return;
        }
    }
    if (this->actionDelay == 0 || gLinkState.field_0x10[2] == 0x1e) {
        for (i = ((UnkManagerHelperStruct*) this->field_0x20);i->field_0x00 != 0xFFFF; i++) {
            tmp = (i->field_0x07.all & 0x3);
            if (((tmp & (gLinkEntity.collisionLayer)) != 0) &&
                (((gLinkState.flags.all & 0x80) != 0) || ((i->field_0x07.b.unk2) != 0)) &&
                (CheckPlayerInRegion(i->field_0x00,i->field_0x02,i->field_0x04,i->field_0x05) != 0) &&
                (gLinkEntity.height.HALF.HI == 0)) {
                DoExitTransition(GetCurrentRoomProperty(i->field_0x06));
            }
        }
    }
}
