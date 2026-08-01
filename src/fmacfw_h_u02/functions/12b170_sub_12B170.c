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

extern uint32_t dword_12B250;
extern uint32_t off_12B254;
extern uint32_t dword_12B24C;

// get_bt_device_state @ 0x12b170, size 218 bytes
int  get_bt_device_state(int a1, int a2, int a3)
{
  int v3; // r9
  int v4; // r3
  int v6; // r5
  int v9; // r3
  int v10; // r0
  int result; // r0
  int v12; // r4
  uint16_t *v13; // lr
  int v14; // r1
  uint64_t v15; // kr00_8
  int16_t v16; // r5
  int v17; // r9
  int v18; // r0
  int v19; // r9

  v3 = dword_12B250;
  v4 = dword_12B250 + 1320 * a1;
  v6 = *(uint8_t *)(v4 + 116);
  if ( *(uint8_t *)(v4 + 1224) )
  {
    result = lock_acquire(1, 26);
    v12 = result;
    if ( result )
    {
LABEL_5:
      v13 = off_12B254;
      v14 = dword_12B24C + 696 * v6;
      v15 = *(uint64_t *)(result + 72);
      v16 = *((uint16_t *)off_12B254 + 254);
      *(uint32_t *)(v15 + 112) = *(uint32_t *)(v14 + 38);
      v17 = v3 + 1320 * a1;
      *(uint8_t *)(v15 + 108) = 64;
      *(uint16_t *)(v15 + 116) = *(uint16_t *)(v14 + 42);
      v18 = *(uint32_t *)(v17 + 100);
      LOWORD(v17) = *(uint16_t *)(v17 + 104);
      *(uint32_t *)(v15 + 118) = v18;
      LOWORD(v18) = *(uint16_t *)(v14 + 42);
      *(uint16_t *)(v15 + 122) = v17;
      ++v16;
      v19 = *(uint32_t *)(v14 + 38);
      *(uint16_t *)(v15 + 128) = v18;
      *(uint8_t *)(v15 + 109) = 0;
      *(uint8_t *)(v15 + 110) = 0;
      *(uint8_t *)(v15 + 111) = 0;
      *(uint32_t *)(v15 + 124) = v19;
      v13[254] = v16;
      *(uint8_t *)(v15 + 132) = 0;
      *(uint8_t *)(v15 + 133) = 0;
      *(uint16_t *)(v15 + 130) = 16 * v16;
      *(uint32_t *)(HIDWORD(v15) + 24) = 0;
      *(uint8_t *)(v12 + 28) = a1;
      *(uint8_t *)(v12 + 29) = *(uint8_t *)(v14 + 35);
      *(uint32_t *)(v12 + 88) = a2;
      *(uint32_t *)(v12 + 92) = a3;
      return sec_check(v12, 5);
    }
  }
  else
  {
    v9 = *(uint32_t *)(v4 + 72);
    v10 = *(uint8_t *)(v9 + 4);
    if ( *(uint8_t *)(v9 + 4) )
      v10 = 1;
    result = lock_acquire(v10, 26);
    v12 = result;
    if ( result )
      goto LABEL_5;
  }
  return result;
}

