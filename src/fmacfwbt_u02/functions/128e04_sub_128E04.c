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

extern uint32_t dword_128E48;
extern uint32_t off_128E50;
extern uint32_t off_128E4C;
extern uint32_t off_128E54;
extern uint32_t dword_128E58;

// dump_hex_value @ 0x128e04, size 66 bytes
int  dump_hex_value(int a1, int a2)
{
  int result; // r0
  uint8_t *v4; // r5
  int v5; // r3

  result = is_log_enabled(a1, a2, dword_128E48);
  if ( result )
  {
    v4 = off_128E50;
    v5 = *((uint8_t *)off_128E4C + 2);
    *((uint8_t *)off_128E50 + 28) = 0;
    if ( v5 )
      *(uint32_t *)off_128E54 |= 0x80000000;
    if ( v4[8] )
      --v4[8];
    result = ke_event_set_lock(dword_128E58);
    v4[29] = 0;
    *(uint32_t *)(a1 + 4) &= 0xFFFFFDF9;
  }
  return result;
}

