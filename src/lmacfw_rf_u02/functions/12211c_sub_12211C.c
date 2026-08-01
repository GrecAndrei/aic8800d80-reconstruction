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

extern uint32_t dword_122188;
extern uint32_t dword_12218C;
extern uint32_t off_122194;
extern uint32_t off_122190;

// parse_len_value @ 0x12211c, size 108 bytes
int  parse_len_value(int a1, int a2)
{
  int v3; // r5
  int v4; // r4
  int v5; // r0
  uint32_t *v6; // r3

  if ( a1 <= 2 )
  {
    v4 = parse_number(*(uint8_t **)(a2 + 4), 0, 0x10u);
    dispatch_event_handler(dword_122188, v4);
    goto LABEL_5;
  }
  v3 = parse_number(*(uint8_t **)(a2 + 4), 0, 0);
  v4 = parse_number(*(uint8_t **)(a2 + 8), 0, 0x10u);
  dispatch_event_handler(dword_122188, v4);
  if ( v3 == 1 )
LABEL_5:
    v4 = *(uint32_t *)(v4 + 4);
  v5 = dispatch_event_handler(dword_12218C, v4);
  v6 = off_122194;
  *((uint32_t *)off_122190 + 65) = 8;
  v6[2] &= ~0x20000u;
  v6[2] |= 0x40000u;
  ((void ( *)(int))v4)(v5);
  return 0;
}

