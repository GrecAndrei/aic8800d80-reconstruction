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


extern uint32_t dword_107EC8;
extern uint32_t off_107EC0;
extern uint32_t off_107ED0;
extern uint32_t off_107ED4;

// rf_mmio_set_amp @ 0x107dac, size 276 bytes
int  rf_mmio_set_amp(int a1, uint32_t *a2)
{
  uint32_t *v2; // r6
  unsigned int *v3; // r8
  int v4; // r7
  int v6; // r9
  int *v7; // r4
  int v8; // r11
  int v9; // r10
  int v10; // r0
  int v11; // t1
  int v12; // r3
  int v13; // r2
  int v14; // r5
  unsigned int *v15; // r3
  int v16; // r2
  int v18; // [sp+8h] [bp-1Ch]
  int v19; // [sp+Ch] [bp-18h]
  int v20; // [sp+10h] [bp-14h]
  int v21; // [sp+14h] [bp-10h]
  int v22; // [sp+18h] [bp-Ch]

  v2 = off_107EC0;
  v3 = (unsigned int *)off_107ED4;
  *(uint32_t *)off_107EC0 |= 0x1000000u;
  v4 = 1;
  *v2 &= ~0x2000000u;
  v6 = 1000;
  state_check_feature(1, &aAdjPwr[4]);
  v7 = (int *)(a1 + 12);
  v21 = 1;
  v22 = 1;
  v19 = 1;
  v18 = 1;
  v20 = 1;
  v8 = 1;
  v9 = 1000;
  do
  {
    while ( 1 )
    {
      v10 = v7[10];
      v11 = v7[1];
      ++v7;
      *v3 = dword_107EC8 & (v10 << 16) | *v3 & 0xF000FFFF;
      *v3 = v11 & 0xFFF | *v3 & 0xFFFFF000;
      timer_set(40);
      v12 = v7[9];
      v13 = *v7;
      *v2 |= 0x4000000u;
      v14 = *(uint32_t *)off_107ED0 & 0x7FFF;
      *v2 &= ~0x4000000u;
      state_check_feature(1, "am=%4d,ph=%4d,%d\n", v13, v12, v14);
      if ( v14 >= v6 )
        break;
      v21 = v19;
      v22 = v18;
      v19 = v7[9];
      v20 = v8;
      v9 = v6;
      v18 = *v7;
      v6 = v14;
      v8 = v4;
LABEL_3:
      if ( ++v4 == 10 )
        goto LABEL_7;
    }
    if ( v14 >= v9 )
      goto LABEL_3;
    v20 = v4++;
    v22 = *v7;
    v21 = v7[9];
    v9 = v14;
  }
  while ( v4 != 10 );
LABEL_7:
  v15 = (unsigned int *)off_107EC0;
  v16 = *(uint32_t *)off_107EC0;
  a2[5] = v18;
  a2[6] = v19;
  a2[7] = v22;
  a2[3] = v6;
  a2[8] = v21;
  a2[9] = v8;
  a2[4] = v9;
  a2[10] = v20;
  *v15 = v16 & 0xFEFFFFFF;
  *v15 &= ~0x2000000u;
  return v20;
}
