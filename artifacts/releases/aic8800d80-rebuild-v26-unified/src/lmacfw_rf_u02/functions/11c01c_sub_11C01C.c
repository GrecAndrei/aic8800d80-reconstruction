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

extern uint32_t off_11C144;
extern uint32_t off_11C150;
extern uint32_t dword_11C148;
extern uint32_t off_11C14C;
extern uint32_t off_11C154;

// sub_11C01C @ 0x11c01c, size 296 bytes
int  sub_11C01C(int result)
{
  uint32_t *v1; // r5
  int v2; // r4
  int v3; // r6
  int v4; // r3
  int v5; // r2
  int v6; // r7
  int v7; // r8
  int v8; // r7
  int v9; // r4
  int v10; // r3
  int *v11; // r4
  int v12; // r1
  int v13; // r3
  int v14; // r2
  int v15; // r0
  int *v16; // r2
  int v17; // r2

  v1 = off_11C144;
  if ( *((uint8_t *)off_11C144 + 90) <= 1u )
    return result;
  v2 = result;
  if ( (*(uint8_t *)(result + 85) & 2) != 0 )
    return result;
  v3 = *((uint32_t *)off_11C144 + 9);
  if ( (*(uint8_t *)(result + 85) & 4) != 0 )
    *(uint8_t *)(result + 85) &= ~4u;
  if ( !v3 || *(uint32_t *)(v3 + 12) != result + 76 )
    return rf_cal_or_init_handler(result, *(uint32_t *)(result + 36), 0);
  v6 = *(uint32_t *)(result + 80);
  v7 = *(uint32_t *)(result + 36);
  if ( v6 - v7 >= 0 )
    goto LABEL_14;
  if ( v7 - 4000 - v6 - sub_101A20() >= 0 )
  {
    v7 = *(uint32_t *)(v2 + 36);
    v6 = *(uint32_t *)(v2 + 80);
LABEL_14:
    if ( v7 - v6 >= 0 || v6 - 4000 - v7 - sub_101A20() >= 0 )
    {
      rf_init_or_query();
      rf_cal_or_init_handler(v2, *(uint32_t *)(v2 + 36), 0);
      return sub_11B088(v2, *((uint32_t *)off_11C150 + 4), 0);
    }
  }
  v8 = *(uint32_t *)(v2 + 36);
  *(uint32_t *)(v2 + 80) = v8;
  result = sub_101A20();
  if ( v8 - *(uint32_t *)(v3 + 4) - result - 4000 < 0 )
  {
    v9 = *(uint32_t *)(v2 + 80);
    result = sub_101A20();
    v10 = v1[18];
    *(uint32_t *)(v3 + 4) = v9 - 4000 - result;
    if ( v10 == v3 )
    {
      timestamp_remove(dword_11C148);
      v1[18] = v3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_11C14C = 1;
      }
      v11 = (int *)off_11C154;
      v12 = *(uint32_t *)(v3 + 4);
      v13 = *(uint32_t *)off_11C154;
      v14 = v12 - *((uint32_t *)off_11C150 + 4);
      v15 = *(uint32_t *)off_11C154 + 1;
      *(uint32_t *)off_11C154 = v15;
      if ( v14 - 64 >= 0 )
      {
        result = sub_11AB18(dword_11C148, v12);
        if ( *v11 )
        {
          v4 = *v11 - 1;
          v5 = *(uint32_t *)off_11C14C;
          *v11 = v4;
          if ( !v4 )
          {
            if ( v5 )
              __enable_irq();
          }
        }
      }
      else
      {
        if ( v15 )
        {
          v16 = (int *)off_11C14C;
          *v11 = v13;
          v17 = *v16;
          if ( !v13 )
          {
            if ( v17 )
              __enable_irq();
          }
        }
        return ((int ( *)(int))v1[17])(v3);
      }
    }
  }
  return result;
}

