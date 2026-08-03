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

extern uint32_t off_12406C;
extern uint32_t off_124068;
extern uint32_t off_124074;
extern uint32_t off_124070;
extern uint32_t dword_124078;

// sub_123FF0 @ 0x123ff0, size 118 bytes
int  sub_123FF0(unsigned int a1, int a2, int a3)
{
  int v3; // r4
  unsigned int *v4; // r5
  unsigned int v5; // r2
  int *v6; // r5
  int v7; // r3

  if ( !a1 )
  {
    if ( !a2 )
    {
      v3 = 1024;
      goto LABEL_4;
    }
LABEL_3:
    v3 = a3 << 9;
LABEL_4:
    v4 = (unsigned int *)off_12406C;
    v5 = *(uint32_t *)off_12406C & 0xE3FFFFFF;
    *(uint32_t *)off_124068 = *(uint32_t *)off_124068 & 0xFFFFC180 | a2 & 0xFFFFF9FF | (a1 << 11) | v3;
    *v4 = v5;
LABEL_8:
    ++*(uint8_t *)off_124074;
    return 0;
  }
  if ( a1 <= 4 )
    goto LABEL_3;
  if ( (*(uint32_t *)off_124070 & 1) == 0 )
  {
    v6 = (int *)off_12406C;
    v7 = *(uint32_t *)off_12406C | 0x10000000;
    *(uint32_t *)off_124068 = *(uint32_t *)off_124068 & 0xFFFFC780 | a2 | (a1 << 11);
    *v6 = v7;
    goto LABEL_8;
  }
  msg_parse(dword_124078, a1, a3, *(uint32_t *)off_124070 << 31);
  return 1;
}

