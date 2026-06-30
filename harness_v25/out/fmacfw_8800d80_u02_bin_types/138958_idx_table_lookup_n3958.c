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

extern uint32_t off_1389BC;
extern uint32_t dword_1389C0;
extern uint32_t dword_1389C4;

// idx_table_lookup_n3958 @ 0x138958, size 100 bytes
// Doc: idx_table_lookup_n3958 [util]: Index into table field with byte index from struct header
// idx_table_lookup_n3958 [util]: Index into table field with byte index from struct header
int  idx_table_lookup_n3958(int result)
{
  int v1; // r1
  int16_t **v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  int v6; // r3
  int16_t v7; // r2
  int v8; // r0
  int v9; // r3

  if ( *(uint32_t *)(result + 4 * (*(uint8_t *)(result + 10) + 4)) )
  {
    v1 = *(uint8_t *)(result + 11);
    v2 = (int16_t **)off_1389BC;
    v3 = dword_1389C0;
    v4 = dword_1389C4;
    v5 = result;
    do
    {
      if ( **v2 < 0 && !v1 )
      {
        sub_12F46C(v4, v3, 1537);
        LOBYTE(v1) = *(uint8_t *)(v5 + 11);
      }
      v6 = *(uint8_t *)(v5 + 10);
      v7 = *(uint16_t *)(v5 + 8);
      v8 = v6 + 4;
      v9 = ((uint8_t)v6 + 1) & 0x3F;
      *(uint32_t *)(v5 + 4 * v8) = 0;
      v1 = (uint8_t)(v1 - 1);
      *(uint8_t *)(v5 + 10) = v9;
      *(uint8_t *)(v5 + 11) = v1;
      result = *(uint32_t *)(v5 + 4 * (v9 + 4));
      *(uint16_t *)(v5 + 8) = (v7 + 1) & 0xFFF;
    }
    while ( result );
  }
  return result;
}

