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

extern uint32_t dword_114910;
extern uint32_t off_114904;
extern uint32_t dword_114908;
extern uint32_t dword_11490C;

// sub_114880 @ 0x114880, size 132 bytes
int  sub_114880(int a1, uint8_t *a2, int a3, int a4)
{
  int16_t v5; // r6
  int16_t v6; // r7
  uint8_t *v7; // r5
  int v8; // r9
  int v9; // r8
  int v10; // r0
  uint16_t *v11; // r3
  int v12; // r0

  v5 = a4;
  v6 = a3;
  v7 = (uint8_t *)rf_bus_setup_n3a8(3089, a4, a3, 1);
  v8 = *(uint32_t *)a2;
  v9 = a2[4];
  v10 = sub_114790(a2 + 4);
  if ( v10 < 0 )
  {
    sub_12ECB0(dword_114910, v9, v8);
    sub_12CBB4(v7);
    return 0;
  }
  else if ( v8 == v10 )
  {
    v11 = off_114904;
    *((uint16_t *)off_114904 + 12) = v6;
    v11[13] = v5;
    sub_11469C(a2);
    v12 = dword_114908;
    *v7 = 1;
    sub_12ECB0(v12, v9, v8);
    sub_12CBB4(v7);
    return 1;
  }
  else
  {
    sub_12ECB0(dword_11490C, v10, v8);
    sub_12CBB4(v7);
    return 0;
  }
}

