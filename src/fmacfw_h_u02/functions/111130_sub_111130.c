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

extern uint32_t dword_1111B0;
extern uint32_t dword_1111A8;
extern uint32_t dword_1111AC;

// kmalloc @ 0x111130, size 118 bytes
int  kmalloc(char a1, int a2, int a3)
{
  uint32_t *v6; // r0
  uint32_t *v7; // r4
  uint32_t *v8; // r6
  int v9; // r2
  int v10; // r3

  v6 = is_chip_ready(4);
  if ( !v6 )
    return debug_printf(dword_1111B0);
  v7 = v6;
  v8 = (uint32_t *)mmio_read_0();
  if ( v8 )
  {
    *(uint8_t *)v7 = a3;
    *((uint8_t *)v7 + 1) = BYTE1(a3) & 0xF;
    *((uint8_t *)v7 + 2) = a1;
    *((uint8_t *)v7 + 3) = 0;
    memcpy(v7 + 1, a2, a3);
    v9 = v8[2];
    v10 = dword_1111A8;
    v8[1] = 0;
    *v8 = v7;
    v8[2] = (uint16_t)(a3 + 4) | v10 & v9 | 0x80000000;
    return memcpy((int)v8);
  }
  else
  {
    debug_printf(dword_1111AC);
    return wait_for_state(v7);
  }
}

