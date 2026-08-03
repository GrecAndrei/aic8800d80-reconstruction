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

extern uint32_t off_11B350;
extern uint32_t off_11B354;
extern uint32_t dword_11B364;
extern uint32_t dword_11B360;
extern uint32_t dword_11B358;
extern uint32_t dword_11B368;
extern uint32_t dword_11B35C;

// sub_11B2C8 @ 0x11b2c8, size 134 bytes
// Doc: sub_121B2C8 [unknown]: Checks a flag byte from a global struct and shifts it, branches on result
// sub_121B2C8 [unknown]: Checks a flag byte from a global struct and shifts it, branches on result
int sub_11B2C8()
{
  uint8_t *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = off_11B350;
  v1 = *((uint8_t *)off_11B350 + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(int16_t **)off_11B354 < 0 && (v1 & 4) != 0 )
    {
      rf_cmd_send_n264(dword_11B364, dword_11B360, 1720);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xFA | 4;
    return rf_mailbox_post_n44(dword_11B358);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(int16_t **)off_11B354 < 0 && (v1 & 8) != 0 )
    {
      rf_cmd_send_n264(dword_11B368, dword_11B360, 1731);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xF5 | 8;
    return rf_mailbox_post_n44(dword_11B35C);
  }
  return result;
}

