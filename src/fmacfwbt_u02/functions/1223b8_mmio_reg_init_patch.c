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

extern uint32_t dword_122430;
extern uint32_t dword_122434;
extern uint32_t dword_122438;
extern uint32_t off_12242C;
extern uint32_t off_12243C;
extern uint32_t off_122444;
extern uint32_t off_122448;
extern uint32_t off_122440;
extern uint32_t dword_12244C;

// mmio_reg_init_patch @ 0x1223b8, size 116 bytes
// Doc: mmio_reg_init_patch [mmio]: Initialize MMIO control registers with patch flags
// mmio_reg_init_patch [mmio]: Initialize MMIO control registers with patch flags
int  mmio_reg_init_patch(int a1)
{
  int *v1; // r3
  int v2; // r6
  int v3; // r5
  int *v4; // r0
  int *v5; // r1
  int v6; // r2
  int v7; // t1
  int v8; // r4
  uint8_t *v9; // r4
  uint8_t *v10; // r1
  uint8_t *v11; // r2
  int v12; // r1
  int v13; // r2
  uint32_t v15[7]; // [sp+0h] [bp-1Ch] BYREF

  v1 = (int *)dword_122430;
  v2 = dword_122434;
  v3 = dword_122438;
  v4 = (int *)(a1 + 12);
  v5 = (int *)(*(uint32_t *)off_12242C + 4);
  do
  {
    v7 = *v5++;
    v6 = v7;
    v8 = v7 & 0xFFF;
    if ( v7 )
    {
      if ( !v8 )
      {
        *v1 = *v4 & 0xFFF | v6 & v2;
        goto LABEL_5;
      }
    }
    else
    {
      v6 = *v4;
    }
    *v1 = v6;
LABEL_5:
    ++v1;
    ++v4;
  }
  while ( v1 != (int *)v3 );
  v9 = off_12243C;
  rf_power_set(*((uint8_t *)off_12243C + 409));
  v10 = off_122444;
  v11 = off_122448;
  *((uint8_t *)off_122440 + 7) = v9[409];
  memset(&v15[1], 0, 16);
  *v10 = 0;
  v15[0] = 0;
  *v11 = 0;
  v15[5] = 0;
  sub_118104((int)v15);
  return sub_12ECB0(dword_12244C, v12, v13);
}

