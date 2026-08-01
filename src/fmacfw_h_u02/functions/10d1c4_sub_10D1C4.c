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

extern uint32_t off_10D248;
extern uint32_t off_10D24C;
extern uint32_t dword_10D254;
extern uint32_t off_10D250;
extern uint32_t off_10D25C;
extern uint32_t dword_10D268;
extern uint32_t off_10D264;

// wait_radio_flag @ 0x10d1c4, size 130 bytes
int wait_radio_flag()
{
  int v0; // r4
  int v2; // r1
  char *v3; // r2
  unsigned int v4; // r4
  int v5; // r5
  int v6; // r1

  if ( (*((uint32_t *)off_10D248 + 75) & 0x80) == 0 )
    return 1;
  v0 = (*(uint32_t *)off_10D24C >> 3) & 1;
  if ( (*(uint32_t *)off_10D24C & 8) != 0 )
  {
    v0 = (*(uint32_t *)off_10D24C >> 1) & 1;
    if ( (*(uint32_t *)off_10D24C & 2) != 0 )
    {
      v2 = dword_10D254;
      v3 = (char *)off_10D24C + 5050236;
      *(uint32_t *)off_10D250 = 0x200000;
      *((uint32_t *)v3 + 1) |= 0x400000u;
      check_feature_flag(2, v2);
      do
      {
        v4 = *(uint32_t *)off_10D25C;
        v5 = *(uint32_t *)off_10D25C & 0x300000;
      }
      while ( !v5 );
      v6 = dword_10D268;
      *(uint32_t *)off_10D264 = v5;
      v0 = (v4 >> 20) & 1;
      check_feature_flag(2, v6);
    }
  }
  return v0;
}

