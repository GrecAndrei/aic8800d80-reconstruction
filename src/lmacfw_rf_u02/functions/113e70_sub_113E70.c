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

extern uint32_t dword_113ECC;

// tx_desc_build @ 0x113e70, size 92 bytes
int  tx_desc_build(int a1, char a2, uint8_t *a3)
{
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r0
  unsigned int v8; // r3
  int result; // r0
  char v10; // r2
  uint32_t v11[3]; // [sp+4h] [bp-Ch]

  v5 = *(uint32_t *)(dword_113ECC + 4);
  v6 = *(uint32_t *)(dword_113ECC + 8);
  v11[0] = *(uint32_t *)dword_113ECC;
  v11[1] = v5;
  v11[2] = v6;
  v7 = (unsigned int)mmio_read32(v11[a1]) >> (8 * a2);
  v8 = (uint8_t)v7 >> 4;
  if ( (v7 & 0xF0) != 0 )
  {
    result = 0;
  }
  else
  {
    if ( !(uint8_t)v7 )
    {
      *a3 = 0;
      return 2;
    }
    v8 = (uint8_t)v7;
    result = 1;
  }
  if ( (v8 & 1) != 0 )
    v10 = -1;
  else
    v10 = 1;
  *a3 = (v8 >> 1) * v10;
  return result;
}

