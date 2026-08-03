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

extern uint32_t dword_11F130;
extern uint32_t dword_11F154;
extern uint32_t dword_11F138;
extern uint32_t off_11F13C;
extern uint32_t off_11F140;
extern uint32_t dword_11F144;
extern uint32_t off_11F148;
extern uint32_t off_11F14C;
extern uint32_t off_11F150;

// sub_11EFEC @ 0x11efec, size 322 bytes
unsigned int  sub_11EFEC(unsigned int a1)
{
  int v1; // r7
  int v2; // r8
  int v3; // r5
  int v4; // r9
  int v5; // r6
  int v6; // r3
  uint32_t *v8; // r2
  unsigned int v9; // r3
  int v10; // r1
  int v11; // r0
  int v12; // r12
  int v13; // r0
  unsigned int result; // r0
  int v15; // r8
  int *v16; // r0
  int v17; // r2
  int *v18; // r3
  int v19; // r3

  v1 = dword_11F130;
  v2 = dword_11F154;
  v3 = dword_11F130 + 696 * a1;
  v4 = *(uint8_t *)(v3 + 34);
  v5 = 1320 * v4;
  v6 = dword_11F154 + 1320 * v4;
  if ( *(uint8_t *)(v6 + 1224) )
    --*(uint8_t *)(v6 + 1226);
  sub_12EB90(256, dword_11F138);
  sub_12D1A8(v5 + 240 + v2, v3);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11F13C = 1;
  }
  v8 = off_11F140;
  v9 = v1 + 696 * a1;
  v10 = *(uint32_t *)off_11F140;
  v11 = *(uint32_t *)(v9 + 44);
  v12 = *(uint32_t *)off_11F140 + 1;
  *(uint32_t *)off_11F140 = v12;
  *(uint8_t *)(v9 + 37) = 0;
  if ( v11 )
  {
    *(uint8_t *)(v11 + 37) = 0;
    if ( !v12 )
    {
LABEL_7:
      sub_11EC64(v11);
      sub_12D108(dword_11F144);
      goto LABEL_8;
    }
    v16 = (int *)off_11F13C;
    *v8 = v10;
    v17 = *v16;
    if ( v10 )
    {
      v11 = *(uint32_t *)(v9 + 44);
      goto LABEL_7;
    }
  }
  else
  {
    if ( !v12 )
      goto LABEL_8;
    v18 = (int *)off_11F13C;
    *v8 = v10;
    v17 = *v18;
    if ( v10 )
      goto LABEL_8;
  }
  if ( v17 )
    __enable_irq();
  v11 = *(uint32_t *)(v1 + 696 * a1 + 44);
  if ( v11 )
    goto LABEL_7;
LABEL_8:
  sub_11EC64(v3);
  v13 = sub_12D108(dword_11F144);
  result = sub_1227A8(v13);
  if ( !result )
  {
    if ( *((uint8_t *)off_11F148 + 408) )
      result = sub_122044(v2 + v5);
    else
      result = sub_102AD0(0xC2u);
  }
  if ( a1 <= 0x1F )
  {
    v15 = v2 + 1320 * v4;
    if ( *(uint8_t *)(v15 + 106) == 2 && !*(uint8_t *)(v15 + 1224) )
    {
      if ( !*(uint8_t *)off_11F14C
        || (v19 = (uint8_t)(*(uint8_t *)off_11F14C - 1), *(uint8_t *)off_11F14C = v19, !v19) )
      {
        if ( *((uint8_t *)off_11F150 + 18) + *((uint8_t *)off_11F150 + 17) == 1 )
          return sub_136D34(result);
      }
    }
  }
  return result;
}

