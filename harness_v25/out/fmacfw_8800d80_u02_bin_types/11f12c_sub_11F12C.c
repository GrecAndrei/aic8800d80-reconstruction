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

extern uint32_t dword_11F270;
extern uint32_t dword_11F294;
extern uint32_t dword_11F278;
extern uint32_t off_11F27C;
extern uint32_t off_11F280;
extern uint32_t dword_11F284;
extern uint32_t off_11F288;
extern uint32_t off_11F28C;
extern uint32_t off_11F290;

// sub_11F12C @ 0x11f12c, size 322 bytes
unsigned int  sub_11F12C(unsigned int a1)
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

  v1 = dword_11F270;
  v2 = dword_11F294;
  v3 = dword_11F270 + 696 * a1;
  v4 = *(uint8_t *)(v3 + 34);
  v5 = 1320 * v4;
  v6 = dword_11F294 + 1320 * v4;
  if ( *(uint8_t *)(v6 + 1224) )
    --*(uint8_t *)(v6 + 1226);
  feature_guard_check(256, dword_11F278);
  sub_12D2E8(v5 + 240 + v2, v3);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11F27C = 1;
  }
  v8 = off_11F280;
  v9 = v1 + 696 * a1;
  v10 = *(uint32_t *)off_11F280;
  v11 = *(uint32_t *)(v9 + 44);
  v12 = *(uint32_t *)off_11F280 + 1;
  *(uint32_t *)off_11F280 = v12;
  *(uint8_t *)(v9 + 37) = 0;
  if ( v11 )
  {
    *(uint8_t *)(v11 + 37) = 0;
    if ( !v12 )
    {
LABEL_7:
      obj_read_field_23c(v11);
      list_push_tail(dword_11F284);
      goto LABEL_8;
    }
    v16 = (int *)off_11F27C;
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
    v18 = (int *)off_11F27C;
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
  obj_read_field_23c(v3);
  v13 = list_push_tail(dword_11F284);
  result = sub_1228E8(v13);
  if ( !result )
  {
    if ( *((uint8_t *)off_11F288 + 408) )
      result = mmio_region_setup_n148(v2 + v5);
    else
      result = sub_102B80(0xC2u);
  }
  if ( a1 <= 0x1F )
  {
    v15 = v2 + 1320 * v4;
    if ( *(uint8_t *)(v15 + 106) == 2 && !*(uint8_t *)(v15 + 1224) )
    {
      if ( !*(uint8_t *)off_11F28C
        || (v19 = (uint8_t)(*(uint8_t *)off_11F28C - 1), *(uint8_t *)off_11F28C = v19, !v19) )
      {
        if ( *((uint8_t *)off_11F290 + 18) + *((uint8_t *)off_11F290 + 17) == 1 )
          return sub_136E74(result);
      }
    }
  }
  return result;
}

