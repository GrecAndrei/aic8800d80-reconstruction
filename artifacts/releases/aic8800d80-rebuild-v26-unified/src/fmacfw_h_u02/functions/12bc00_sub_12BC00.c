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

extern uint32_t off_12BCD8;
extern uint32_t off_12BCE0;
extern uint32_t off_12BCE4;
extern uint32_t off_12BCE8;
extern uint32_t off_12BCDC;
extern uint32_t off_12BCF0;
extern uint32_t dword_12BCF8;
extern uint32_t dword_12BCF4;
extern uint32_t off_12BCEC;
extern uint32_t dword_12BCFC;

// sub_12BC00 @ 0x12bc00, size 214 bytes
int sub_12BC00()
{
  int v0; // r4
  int v1; // r5
  uint16_t *v2; // r6
  int v3; // r2
  int v4; // r1
  uint32_t *v6; // r3

  v0 = (*(uint32_t *)off_12BCD8 >> 25) & 1;
  if ( (*(uint32_t *)off_12BCD8 & 0x2000000) == 0
    && 32 * *(uint32_t *)off_12BCE0
     - 2000
     - *((uint16_t *)off_12BCE4 + 92)
     - *((uint16_t *)off_12BCE4 + 93) < 0 )
  {
    return v0;
  }
  v1 = *(uint32_t *)off_12BCE8;
  if ( !*(uint32_t *)off_12BCE8 )
    return 1;
  v2 = (uint16_t *)off_12BCE4;
  v3 = *(uint32_t *)(v1 + 12);
  v4 = *((uint16_t *)off_12BCE4 + 93);
  if ( v3 - *((uint32_t *)off_12BCDC + 4) - 2000 - *((uint16_t *)off_12BCE4 + 92) - v4 < 0 )
  {
    if ( **(int16_t **)off_12BCF0 < 0 && v3 - *((uint32_t *)off_12BCDC + 4) + 5000 < 0 )
    {
      sub_12F32C(dword_12BCF8, dword_12BCF4, 575);
      return 0;
    }
    return 0;
  }
  else
  {
    if ( **(uint8_t **)off_12BCEC != 1 )
      return 1;
    if ( **(int16_t **)off_12BCF0 < 0 && v3 - *((uint32_t *)off_12BCDC + 4) - v4 < 0 )
    {
      sub_12F32C(dword_12BCFC, dword_12BCF4, 580);
      v3 = *(uint32_t *)(v1 + 12);
      v4 = v2[93];
    }
    v6 = off_12BCDC;
    *((uint32_t *)off_12BCDC + 2) = 0x40000;
    v6[12] = v3 - v4;
    v6[2] = 4;
    return 1;
  }
}

