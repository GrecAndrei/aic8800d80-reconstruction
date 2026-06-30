#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t off_1262EC;
extern uint32_t dword_126328;
extern uint32_t off_1262F4;
extern uint32_t off_1262F8;
extern uint32_t off_1262FC;
extern uint32_t off_126300;
extern uint32_t off_1262F0;
extern uint32_t off_126304;
extern uint32_t dword_126308;
extern uint32_t dword_12630C;
extern uint32_t off_126314;
extern uint32_t off_126318;
extern uint32_t off_12631C;
extern uint32_t off_126310;
extern uint32_t dword_126324;
extern uint32_t off_126320;

// sub_126258 @ 0x126258, size 148 bytes
int  sub_126258(int a1, int a2, char a3)
{
  uint8_t *v3; // r5
  uint8_t *v5; // r3
  uint8_t *v6; // r0
  uint8_t *v7; // r1
  uint8_t *v8; // r2
  uint32_t *v9; // r3
  int *v10; // r0
  uint32_t *v11; // r0
  uint8_t *v12; // r1
  uint8_t *v13; // r2
  int v14; // r0

  v3 = off_1262EC;
  if ( *(uint8_t *)off_1262EC )
    msg_parse(dword_126328);
  v5 = off_1262F4;
  v6 = off_1262F8;
  v7 = off_1262FC;
  v8 = off_126300;
  *(uint32_t *)off_1262F0 = -1;
  *v5 = 0;
  v9 = off_126304;
  *v6 = 0;
  *v7 = 0;
  *v8 = a3;
  v10 = (int *)dword_126308;
  *v9 |= 0x100u;
  *v9 |= 0x200u;
  *v9 |= 0x400u;
  sub_100200(v10, 0, 8u);
  msg_parse(dword_12630C);
  v11 = off_126314;
  v12 = off_126318;
  v13 = off_12631C;
  *(uint16_t *)off_126310 = 0;
  *v11 = 0;
  *v12 = 1;
  *v13 = 1;
  sub_10F170(16);
  v14 = dword_126324;
  *(uint32_t *)off_126320 = *(uint32_t *)off_126320 & 0xFF03FFFF | 0x800000;
  *v3 = 5;
  msg_parse(v14);
  return irq_nesting_or(0x2000);
}

