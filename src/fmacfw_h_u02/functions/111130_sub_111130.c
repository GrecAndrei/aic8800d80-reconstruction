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


extern uint32_t dword_1111A8;

// kmalloc @ 0x111130, size 118 bytes
int  kmalloc(char a1, char *a2, unsigned int a3, int a4)
{
  uint32_t *v7; // r0
  uint32_t *v8; // r4
  uint32_t *v9; // r6
  int v10; // r2
  int v11; // r3

  v7 = is_chip_ready(4);
  if ( !v7 )
    return debug_printf(aErrNoMsgPkt);
  v8 = v7;
  v9 = mmio_read_0();
  if ( v9 )
  {
    *(uint8_t *)v8 = a3;
    *((uint8_t *)v8 + 1) = BYTE1(a3) & 0xF;
    *((uint8_t *)v8 + 2) = a1;
    *((uint8_t *)v8 + 3) = 0;
    memcpy_1((char *)v8 + 4, a2, a3);
    v10 = v9[2];
    v11 = dword_1111A8;
    v9[1] = 0;
    *v9 = v8;
    v9[2] = (uint16_t)(a3 + 4) | v11 & v10 | 0x80000000;
    return memcpy((int)v9);
  }
  else
  {
    debug_printf(aErrSendMsgCfgT);
    return wait_for_state(v8);
  }
}
