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

extern uint32_t off_10107C;
extern uint32_t off_101080;
extern uint32_t off_101084;
extern uint32_t off_101088;
extern uint32_t off_10108C;
extern uint32_t off_101090;
extern uint32_t off_101094;
extern uint32_t off_101098;
extern uint32_t dword_1010A4;
extern uint32_t off_1010A8;
extern uint32_t off_1010AC;
extern uint32_t off_10109C;
extern uint32_t dword_1010A0;
extern uint32_t off_1010B0;
extern uint32_t off_1010B4;
extern uint32_t off_1010B8;
extern uint32_t off_1010BC;
extern uint32_t off_1010C0;
extern uint32_t off_1010C4;
extern uint32_t off_1010C8;
extern uint32_t off_1010CC;
extern uint32_t off_1010D0;

// mac_ctrl_set @ 0x100e00, size 634 bytes
// Doc: mac_ctrl_set [mmio]: Configures MMIO clock/power registers at 0x403440xx
// mac_ctrl_set [mmio]: Configures MMIO clock/power registers at 0x403440xx
int  mac_ctrl_set(unsigned int a1, int a2)
{
  uint32_t *v2; // r3
  uint32_t *v3; // r2
  uint32_t *v4; // r5
  uint32_t *v5; // r6
  uint32_t *v6; // r4
  int v7; // r1
  uint32_t *v8; // r1
  uint32_t *v9; // r2
  int v11; // r4
  int v12; // r3
  unsigned int *v13; // r5
  unsigned int *v14; // r2
  int v15; // r1
  int v16; // r4
  int v17; // r5
  unsigned int *v18; // r4
  uint32_t *v19; // r0
  uint32_t *v20; // r5
  uint8_t *v21; // r2
  unsigned int *v22; // r4
  unsigned int *v23; // r2
  uint32_t *v24; // r5
  unsigned int *v25; // r0
  unsigned int *v26; // r4
  uint32_t *v27; // r2
  unsigned int v28; // r3
  uint32_t *v29; // r2
  unsigned int v30; // r3
  int result; // r0

  v2 = off_10107C;
  v3 = off_101080;
  v4 = off_101084;
  v5 = off_101088;
  *(uint32_t *)off_10107C |= 0x400u;
  *v2 |= 0x800u;
  *v4 &= ~4u;
  *v3 &= ~0x80000u;
  *v3 |= 0x100000u;
  v2[7] &= ~0x400u;
  v2[7] |= 0x100u;
  v2[7] &= ~0x80u;
  v6 = off_10108C;
  *v5 &= ~0x8000u;
  v3[11] &= ~1u;
  v3[11] &= ~2u;
  if ( a2 == 2 )
    v7 = 188416;
  else
    v7 = 385024;
  *(uint32_t *)((char *)v4 + 0xFFFFFFEC) = *(uint32_t *)((char *)v4 + 0xFFFFFFEC) & 0xFFC01FFF | v7;
  v8 = off_101090;
  *v6 &= ~0x40u;
  v3[24] |= 0x8000u;
  v3[24] &= ~0x4000u;
  v9 = off_101094;
  *(uint32_t *)((char *)v4 + 0xFFFFFFF0) &= 0xFFF9FFFF;
  *v8 &= ~1u;
  *(v6 - 1903) |= 8u;
  memcpy_advance(1, 0, 16, *v9);
  memcpy_advance(1, 16, 16, *(uint32_t *)off_101098);
  rf_ctrl_set(0, a1);
  if ( a1 > 0x98A )
  {
    v11 = 6;
  }
  else if ( a1 <= 0x97B )
  {
    v11 = 0;
  }
  else
  {
    v11 = 3;
  }
  v12 = dword_1010A4;
  v13 = (unsigned int *)off_1010A8;
  v14 = (unsigned int *)off_1010AC;
  v15 = *(uint8_t *)off_10109C & 0xC0;
  if ( v15 == 192 )
    v12 = dword_1010A0;
  *(uint32_t *)off_1010A8 = *(uint32_t *)off_1010A8 & 0xFE01FFFF | (*(uint8_t *)(v12 + v11) << 17);
  v16 = v11 + v12;
  *v13 = *v13 & 0xFFFFFF00 | *(uint8_t *)(v16 + 1);
  v17 = *(uint8_t *)(v16 + 2);
  v18 = (unsigned int *)off_1010B0;
  v19 = off_1010B4;
  *v14 = *v14 & 0xFFFFFF00 | v17;
  v20 = off_1010B8;
  *v18 = *v18 & 0xFF00FFFF | 0x2F0000;
  *v19 |= 8u;
  *v19 |= 4u;
  *v14 &= 0xFFFC7FFF;
  *v14 = *v14 & 0xFFFF8FFF | 0x1000;
  v21 = off_1010BC;
  v22 = v18 + 19964;
  *v20 &= 0xFFFFC7FF;
  *v22 = *v22 & 0xFFFFE3FF | 0x1000;
  v19[1984] = v19[1984] & 0xFFFFF83F | 0x400;
  if ( !v21[1] )
  {
    v23 = (unsigned int *)off_1010C0;
    *v22 = *v22 & 0xFFFFFC7F | 0x100;
    *v23 = *v23 & 0x16000 | 0x8000 | *v23 & 0xFFFE1FFF;
  }
  v24 = off_1010C4;
  v25 = (unsigned int *)off_101088;
  v26 = (unsigned int *)off_1010C8;
  v27 = off_101090;
  *(uint32_t *)off_1010C4 |= 0xC00u;
  *v25 = *v25 & 0xFFFFFF87 | 0x48;
  *v26 |= 4u;
  *v27 &= ~2u;
  v26 += 1907;
  v24[2] |= 0x20000u;
  *v26 = *v26 & 0xFFF8FFFF | 0x20000;
  *v26 = *v26 & 0xFFFFFFF0 | 8;
  *(uint32_t *)((char *)v24 + 0xFFFFFFEC) = *(uint32_t *)((char *)v24 + 0xFFFFFFEC) & 0xFFFFE3FF | 0x800;
  *(unsigned int *)((char *)v26 + 0xFFFFFFFC) = *(unsigned int *)((char *)v26 + 0xFFFFFFFC) & 0xFC7FFFFF | 0x1000000;
  *v27 &= ~0x20u;
  v28 = *v25;
  v29 = off_1010CC;
  if ( v15 == 192 )
    v30 = v28 | 0xE0000;
  else
    v30 = v28 & 0xFFF1FFFF;
  if ( v15 != 192 )
    v30 |= 0x60000u;
  *v25 = v30;
  while ( !*v29 )
    ;
  result = *(uint32_t *)off_1010D0 & 1;
  if ( !result )
    result = rf_cal_read_0(0);
  *(uint32_t *)off_1010CC = 1;
  return result;
}

