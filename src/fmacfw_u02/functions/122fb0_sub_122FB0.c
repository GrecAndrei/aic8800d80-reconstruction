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

extern uint32_t dword_12306C;
extern uint32_t off_123070;
extern uint32_t dword_12307C;
extern uint32_t off_123074;
extern uint32_t dword_123078;

// send_cmd_7c @ 0x122fb0, size 186 bytes
int  send_cmd_7c(int a1, uint8_t *a2, int a3, int a4)
{
  int v5; // r1
  int v6; // r2
  uint8_t *v7; // r5
  int v8; // r2
  uint8_t *v9; // r6
  unsigned int v10; // r7
  int v11; // r1
  int v13; // r2
  uint8_t v14[5]; // [sp+7h] [bp-5h] BYREF

  v14[0] = 0;
  v7 = (uint8_t *)ke_msg_alloc(124, a4, a3, 2);
  if ( *a2 )
  {
    event_dispatch(dword_12306C, v5, v6);
    **(uint8_t **)off_123070 = 0;
  }
  else
  {
    event_dispatch(dword_12307C, v5, v6);
    **(uint8_t **)off_123070 = 3;
  }
  rom_get_chip_metal(v14);
  v8 = v14[0];
  v7[1] = v14[0];
  if ( a2[1] )
  {
    v9 = off_123074;
    *((uint8_t *)off_123074 + 188) = (v8 & 0x20) != 0;
    v10 = ((v8 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v13 = (uint8_t)a2[2];
    v9 = off_123074;
    v10 = ((v13 ^ 0x40u) >> 6) & 1;
    *((uint8_t *)off_123074 + 188) = (v13 & 0x20) != 0;
  }
  if ( get_hook_bit_20() )
  {
    v9[188] = 0;
    v11 = 0;
  }
  else
  {
    v11 = (uint8_t)v9[188];
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *((uint16_t *)v9 + 89) |= 0x4000u;
    event_dispatch(dword_123078, v11, v10);
    LOBYTE(v11) = v9[188];
  }
  *v7 = v11;
  ke_msg_send(v7);
  return 0;
}

