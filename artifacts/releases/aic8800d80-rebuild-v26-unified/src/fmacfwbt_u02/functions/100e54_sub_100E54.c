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

extern uint32_t off_1010BC;
extern uint32_t off_1010C0;
extern uint32_t off_1010C4;
extern uint32_t off_1010C8;
extern uint32_t off_1010CC;
extern uint32_t off_1010D0;
extern uint32_t off_1010D4;
extern uint32_t off_1010D8;
extern uint32_t off_1010DC;
extern uint32_t dword_1010E0;
extern uint32_t off_1010E4;
extern uint32_t off_1010E8;
extern uint32_t off_1010EC;
extern uint32_t off_1010F0;
extern uint32_t off_1010F4;
extern uint32_t off_1010F8;
extern uint32_t off_1010FC;
extern uint32_t off_101100;
extern uint32_t off_101104;
extern uint32_t off_101108;

// sub_100E54 @ 0x100e54, size 616 bytes
int  sub_100E54(unsigned int a1, int a2)
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
  unsigned int *v12; // r0
  int v13; // r2
  unsigned int *v14; // r3
  int v15; // r4
  unsigned int *v16; // r5
  int v17; // r1
  uint32_t *v18; // r4
  unsigned int *v19; // r1
  uint8_t *v20; // r0
  unsigned int *v21; // r2
  char *v22; // r2
  unsigned int *v23; // r1
  uint32_t *v24; // r5
  uint32_t *v25; // r0
  uint32_t *v26; // r4
  uint32_t *v27; // r2
  int result; // r0

  v2 = off_1010BC;
  v3 = off_1010C0;
  v4 = off_1010C4;
  v5 = off_1010C8;
  *(uint32_t *)off_1010BC |= 0x400u;
  *v2 |= 0x800u;
  *v4 &= ~4u;
  *v3 &= ~0x80000u;
  *v3 |= 0x100000u;
  v2[7] &= ~0x400u;
  v2[7] |= 0x100u;
  v2[7] &= ~0x80u;
  v6 = off_1010CC;
  *v5 &= ~0x8000u;
  v3[11] &= ~1u;
  v3[11] &= ~2u;
  if ( a2 == 2 )
    v7 = 188416;
  else
    v7 = 385024;
  *(uint32_t *)((char *)v4 + 0xFFFFFFEC) = *(uint32_t *)((char *)v4 + 0xFFFFFFEC) & 0xFFC01FFF | v7;
  v8 = off_1010D0;
  *v6 &= ~0x40u;
  v3[24] |= 0x8000u;
  v3[24] &= ~0x4000u;
  v9 = off_1010D4;
  *(uint32_t *)((char *)v4 + 0xFFFFFFF0) &= 0xFFF9FFFF;
  *v8 &= ~1u;
  *(v6 - 1903) |= 8u;
  sub_102D10(1, 0, 16, *v9);
  sub_102D10(1, 16, 16, *(uint32_t *)off_1010D8);
  sub_1009A0(0, a1);
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
  v12 = (unsigned int *)off_1010DC;
  v13 = dword_1010E0;
  v14 = (unsigned int *)off_1010E4;
  *(uint32_t *)off_1010DC = *(uint32_t *)off_1010DC & 0xFE01FFFF | (*(uint8_t *)(dword_1010E0 + v11) << 17);
  v15 = v11 + v13;
  v16 = (unsigned int *)off_1010E8;
  *v12 = *v12 & 0xFFFFFF00 | *(uint8_t *)(v15 + 1);
  v17 = *(uint8_t *)(v15 + 2);
  v18 = off_1010EC;
  *v14 = *v14 & 0xFFFFFF00 | v17;
  v19 = (unsigned int *)off_1010C8;
  v12 -= 64;
  *v16 = *v16 & 0xFF00FFFF | 0x2F0000;
  *v12 |= 8u;
  *v12 |= 4u;
  v20 = off_1010F0;
  *v14 &= 0xFFFC7FFF;
  *v14 = *v14 & 0xFFFF8FFF | 0x1000;
  *v18 &= 0xFFFFC7FF;
  *v19 = *v19 & 0xFFFFE3FF | 0x1000;
  v16[19966] = v16[19966] & 0xFFFFF83F | 0x400;
  if ( !v20[1] )
  {
    v21 = (unsigned int *)off_1010F4;
    *v19 = *v19 & 0xFFFFFC7F | 0x100;
    *v21 = *v21 & 0x16000 | 0x8000 | *v21 & 0xFFFE1FFF;
  }
  v22 = (char *)off_1010F8;
  v23 = (unsigned int *)off_1010C8;
  v24 = off_1010FC;
  v25 = off_1010D0;
  v26 = off_101100;
  *(uint32_t *)off_1010F8 |= 0xC00u;
  *v23 = *v23 & 0xFFFFFF87 | 0x48;
  *v24 |= 4u;
  *v25 &= ~2u;
  *v26 |= 0x20000u;
  *(uint32_t *)&v22[-12] = *(uint32_t *)&v22[-12] & 0xFFF8FFFF | 0x20000;
  *(uint32_t *)&v22[-12] = *(uint32_t *)&v22[-12] & 0xFFFFFFF0 | 8;
  v27 = off_101104;
  v24[1905] = v24[1905] & 0xFFFFE3FF | 0x800;
  *(uint32_t *)((char *)v26 + 0xFFFFFFE8) = *(uint32_t *)((char *)v26 + 0xFFFFFFE8) & 0xFC7FFFFF | 0x1000000;
  *v25 &= ~0x20u;
  *v23 = *v23 & 0xFFF1FFFF | 0x60000;
  while ( !*v27 )
    ;
  result = *(uint32_t *)off_101108 & 1;
  if ( !result )
    result = sub_100CD0(0);
  *(uint32_t *)off_101104 = 1;
  return result;
}

