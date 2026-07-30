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

extern uint32_t off_123474;
extern uint32_t off_123478;
extern uint32_t dword_12347C;
extern uint32_t off_123480;
extern uint32_t off_123484;
extern uint32_t off_123488;
extern uint32_t off_12348C;

// rf_event_check_n3cc @ 0x1233cc, size 168 bytes
// Doc: rf_event_check_n3cc [rf]: Checks RF event/state with byte compare from constant
// rf_event_check_n3cc [rf]: Checks RF event/state with byte compare from constant
float  rf_event_check_n3cc(uint8_t *a1)
{
  int v1; // r2
  int v2; // r5
  int v3; // r4
  int v4; // r6
  int *v5; // r7
  int v6; // r2
  int v7; // r1
  int v8; // r6
  int v9; // r3
  float v10; // s16
  float result; // r0

  v1 = *(uint8_t *)off_123474;
  v2 = HIWORD(*(uint32_t *)off_123478) & 0x3F;
  v3 = *(uint32_t *)off_123478 & 0xFFF;
  if ( v1 == a1[1] )
  {
    v4 = dword_12347C;
    v5 = (int *)off_123480;
    v6 = v1 - 1;
    *(uint16_t *)(dword_12347C + 8 * v6) = a1[4] | (a1[5] << 8);
    v7 = v4 + 8 * v6;
    LOBYTE(v6) = *(uint8_t *)(v7 + 2);
    v8 = *v5;
    v9 = *(char *)off_123484;
    *(uint8_t *)(v7 + 5) = a1[6];
    *(uint8_t *)(v7 + 2) = v6 + 1;
    *v5 = v9 + v8;
  }
  mmio_write_40320150(*(uint32_t *)off_123488 + 20000);
  v10 = sub_11EAA0(COERCE_UNSIGNED_INT((float)(unsigned int)v3));
  result = sub_11EAA0(COERCE_UNSIGNED_INT((float)(1 << v2)));
  *(float *)off_12348C = (float)((float)(v10 * 10.0) - (float)(result * 10.0)) + *(float *)off_12348C;
  return result;
}

