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

extern uint32_t off_10DE88;
extern uint32_t off_10DE8C;
extern uint32_t dword_10DE90;
extern uint32_t dword_10DE94;
extern uint32_t dword_10DE70;
extern uint32_t dword_10DE78;
extern uint32_t dword_10DE80;
extern uint32_t dword_10DE84;

// sdio_core_reset @ 0x10ddc8, size 162 bytes
int  sdio_core_reset(int result, int a2)
{
  uint32_t *v2; // r4
  uint32_t *v3; // r3
  int v4; // r2
  int v5; // r3
  uint64_t v6; // r8
  uint64_t v7; // r6
  int *v8; // r5
  int *v9; // r10
  uint64_t v10; // r0
  uint64_t v11; // r0
  uint64_t v12; // r0
  int v13; // r0

  v2 = off_10DE88;
  v3 = off_10DE8C;
  v4 = dword_10DE90;
  *(uint32_t *)off_10DE88 = 0;
  v3[14] = 296;
  v5 = dword_10DE94;
  v2[2] = v2[2] & 0xF000FFFF | 0x2000000;
  v2[3] = v4 & v2[3] | 0xA06A000;
  v2[3] = v5 & v2[3] | 0x100230;
  if ( a2 > 0 )
  {
    v6 = *(uint64_t *)&dword_10DE70;
    v7 = *(uint64_t *)&dword_10DE78;
    v8 = (int *)result;
    v9 = (int *)(result + 4 * a2);
    do
    {
      v2[1] = 1;
      while ( v2[7] != 1 )
        ;
      v2[7] = 1;
      v10 = double_to_float(v2[4]);
      v11 = aeabi_dadd(v10, HIDWORD(v10), v6, HIDWORD(v6));
      v12 = aeabi_dsub(v11, HIDWORD(v11), v7, HIDWORD(v7));
      v13 = double_subtract(v12, HIDWORD(v12), dword_10DE80, dword_10DE84);
      result = aeabi_dmul(v13);
      *v8++ = result;
    }
    while ( v8 != v9 );
  }
  return result;
}

