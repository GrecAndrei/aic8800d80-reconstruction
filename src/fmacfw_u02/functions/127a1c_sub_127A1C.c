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

extern uint32_t off_127AAC;
extern uint32_t off_127AA8;
extern uint32_t dword_127AB0;
extern uint32_t dword_127AB4;
extern uint32_t off_127ACC;
extern uint32_t off_127AC8;

// stat_clear @ 0x127a1c, size 140 bytes
int stat_clear()
{
  int *v0; // r7
  void *v1; // r6
  unsigned int v2; // r5
  int *i; // r4
  int result; // r0
  uint32_t *v5; // r3
  void *v6; // r1

  v0 = (int *)off_127AAC;
  v1 = off_127AA8;
  memset((int *)off_127AA8, 0, 0x60u);
  v2 = 0;
  for ( i = v0; ; i += 7 )
  {
    memset(i, 0, 0x1Cu);
    *((uint16_t *)i + 7) = 255;
    *((uint8_t *)i + 24) = -1;
    *((uint8_t *)i + 27) = -1;
    if ( v2 <= 2 )
    {
      cmd_handler_a(v1);
      goto LABEL_4;
    }
    if ( v2 != 3 )
      break;
    *((uint16_t *)v0 + 47) = 0;
    *((uint8_t *)v0 + 89) = 0;
LABEL_4:
    ++v2;
  }
  if ( v2 != 4 )
    goto LABEL_4;
  zero_8_bytes(dword_127AB0);
  zero_8_bytes(dword_127AB4);
  cmd_handler_a(dword_127AB0);
  cmd_handler_a(dword_127AB0);
  cmd_handler_a(dword_127AB0);
  result = cmd_handler_a(dword_127AB0);
  v5 = off_127AA8;
  v6 = off_127ACC;
  *((uint32_t *)off_127AA8 + 13) = off_127AC8;
  v5[17] = v6;
  v5[18] = 0;
  return result;
}

