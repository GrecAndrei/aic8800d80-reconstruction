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

extern uint32_t dword_1032C8;
extern uint32_t off_1032CC;
extern uint32_t dword_1032D4;
extern uint32_t dword_1032D0;
extern uint32_t off_1032E4;
extern uint32_t off_1032DC;
extern uint32_t off_1032E0;
extern uint32_t off_1032D8;

// load_and_store_block @ 0x103258, size 112 bytes
uint32_t *load_and_store_block()
{
  int v0; // r1
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  uint8_t *v4; // r2
  int v5; // r1
  unsigned int v6; // r2
  unsigned int v7; // r3
  uint32_t *result; // r0
  unsigned int *v9; // r1
  unsigned int v10; // r3
  int v11; // [sp+0h] [bp-14h]
  int v12; // [sp+4h] [bp-10h]
  int v13; // [sp+8h] [bp-Ch]
  int v14; // [sp+Ch] [bp-8h]
  uint8_t v15[4]; // [sp+10h] [bp-4h] BYREF

  v0 = *(uint32_t *)(dword_1032C8 + 4);
  v1 = *(uint32_t *)(dword_1032C8 + 8);
  v2 = *(uint32_t *)(dword_1032C8 + 12);
  v11 = *(uint32_t *)dword_1032C8;
  v12 = v0;
  v13 = v1;
  v14 = v2;
  if ( (*((uint32_t *)off_1032CC + 4) & 2) != 0 )
  {
    v3 = dword_1032D4;
    v4 = &v15[*((uint32_t *)off_1032CC + 9) & 0xF];
    v5 = (char)*(v4 - 16);
    v6 = (uint8_t)*(v4 - 16);
    if ( (*((uint32_t *)off_1032CC + 4) & 4) == 0 )
      v3 = dword_1032D0;
    if ( v5 < 0 )
    {
      v3 *= 2;
      v6 &= 0x7Fu;
    }
    v7 = v3 / v6;
  }
  else
  {
    v7 = 2 * *(uint32_t *)off_1032E4;
  }
  result = off_1032DC;
  v9 = (unsigned int *)off_1032E0;
  v10 = v7 / (uint8_t)*((uint32_t *)off_1032CC + 8);
  *(uint32_t *)off_1032D8 = v10;
  *v9 = v10 / (uint8_t)result[9];
  return result;
}

