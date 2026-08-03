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

extern uint32_t dword_11C384;
extern uint32_t off_11C388;

// rf_get_status_byte_n_a24 @ 0x11c324, size 96 bytes
// Doc: rf_get_status_byte_n_a24 [rf]: Reads a single status byte at offset 0x19 from a structure
// rf_get_status_byte_n_a24 [rf]: Reads a single status byte at offset 0x19 from a structure
int  rf_get_status_byte_n_a24(int result)
{
  int v1; // r3
  int v2; // r2
  int v3; // r1
  int v4; // r3
  uint32_t *v5; // r2
  uint32_t *v6; // r2

  if ( *(uint8_t *)(result + 25) )
  {
    v1 = 0;
    v2 = dword_11C384;
    while ( 1 )
    {
      v3 = *(uint32_t *)(v2 + 72);
      v2 += 224;
      if ( v3 == result )
        break;
      if ( ++v1 == 4 )
      {
        v4 = 15;
        goto LABEL_6;
      }
    }
    v4 = *(char *)(dword_11C384 + 224 * v1 + 97);
    if ( v4 == 127 )
      v4 = 15;
LABEL_6:
    v5 = off_11C388;
    *(uint8_t *)(result + 12) = v4;
    if ( v5[10] == result )
      return sub_11D9F8(v4);
  }
  else
  {
    v6 = off_11C388;
    *(uint8_t *)(result + 12) = 15;
    if ( v6[10] == result )
      return sub_11D9F8(15);
  }
  return result;
}

