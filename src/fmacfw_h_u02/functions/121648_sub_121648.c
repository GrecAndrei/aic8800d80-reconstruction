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

extern uint32_t off_1216C0;
extern uint32_t off_1216C4;
extern uint32_t off_1216C8;
extern uint32_t off_1216CC;
extern uint32_t off_1216D0;
extern uint32_t off_1216D4;
extern uint32_t off_1216D8;
extern uint32_t off_1216DC;
extern uint32_t dword_1216E0;
extern uint32_t off_1216E8;
extern uint32_t dword_1216F0;
extern uint32_t dword_1216EC;
extern uint32_t off_1216E4;

// sub_121648 @ 0x121648, size 118 bytes
unsigned int  sub_121648(int *a1)
{
  uint32_t *v1; // r3
  uint32_t *v2; // r7
  uint32_t *v3; // r4
  uint32_t *v4; // r1
  uint32_t *v5; // r6
  uint32_t *v6; // r5
  int v7; // r7
  int v8; // r0
  int16_t **v9; // r0
  int *v10; // r4
  int v11; // r2
  int16_t *v12; // r3

  v1 = off_1216C0;
  v2 = off_1216C4;
  v3 = off_1216C8;
  v4 = off_1216CC;
  v5 = off_1216D0;
  v6 = off_1216D4;
  *(uint32_t *)off_1216C0 &= ~2u;
  *v1 |= 1u;
  *v2 = 768;
  v7 = *a1;
  v8 = *((uint16_t *)a1 + 2);
  *v5 = 0;
  *v6 = 0;
  *v3 = v7;
  *v4 = v8;
  v9 = (int16_t **)off_1216D8;
  v10 = (int *)off_1216DC;
  v11 = dword_1216E0;
  *v1 &= 0xFFFFF8FF;
  v12 = *v9;
  *v10 = v11;
  if ( *v12 < 0 && *(uint32_t *)off_1216E8 << 28 )
  {
    sub_12F35C(dword_1216F0, dword_1216EC, 472);
    v11 = *v10;
  }
  *(uint32_t *)off_1216E4 = v11 | v10[1];
  return sub_11DF40(0);
}

