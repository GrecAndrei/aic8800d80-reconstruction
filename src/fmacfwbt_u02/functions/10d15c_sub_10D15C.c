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

extern uint32_t off_10D1E0;
extern uint32_t off_10D1E4;
extern uint32_t dword_10D1EC;
extern uint32_t off_10D1E8;
extern uint32_t off_10D1F4;
extern uint32_t dword_10D200;
extern uint32_t off_10D1FC;

// status_poll @ 0x10d15c, size 130 bytes
int status_poll()
{
  int v0; // r4
  int v2; // r1
  char *v3; // r2
  unsigned int v4; // r4
  int v5; // r5
  int v6; // r1

  if ( (*((uint32_t *)off_10D1E0 + 75) & 0x80) == 0 )
    return 1;
  v0 = (*(uint32_t *)off_10D1E4 >> 3) & 1;
  if ( (*(uint32_t *)off_10D1E4 & 8) != 0 )
  {
    v0 = (*(uint32_t *)off_10D1E4 >> 1) & 1;
    if ( (*(uint32_t *)off_10D1E4 & 2) != 0 )
    {
      v2 = dword_10D1EC;
      v3 = (char *)off_10D1E4 + 5050236;
      *(uint32_t *)off_10D1E8 = 0x200000;
      *((uint32_t *)v3 + 1) |= 0x400000u;
      state_check_feature(2, v2);
      do
      {
        v4 = *(uint32_t *)off_10D1F4;
        v5 = *(uint32_t *)off_10D1F4 & 0x300000;
      }
      while ( !v5 );
      v6 = dword_10D200;
      *(uint32_t *)off_10D1FC = v5;
      v0 = (v4 >> 20) & 1;
      state_check_feature(2, v6);
    }
  }
  return v0;
}

