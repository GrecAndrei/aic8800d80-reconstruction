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

extern uint32_t dword_119898;
extern uint32_t off_11989C;
extern uint32_t dword_1198A8;
extern uint32_t off_1198A0;
extern uint32_t dword_1198A4;

// ke_alloc_msg_0x7c @ 0x1197dc, size 186 bytes
int  ke_alloc_msg_0x7c(int a1, uint8_t *a2, int a3, int a4)
{
  int v5; // r1
  uint8_t *v6; // r5
  char v7; // r2
  uint8_t *v8; // r6
  int v9; // r1
  uint8_t v11[5]; // [sp+7h] [bp-5h] BYREF

  v11[0] = 0;
  v6 = (uint8_t *)ke_msg_send(124, a4, a3, 2);
  if ( *a2 )
  {
    dispatch_event_handler(dword_119898, v5);
    **(uint8_t **)off_11989C = 0;
  }
  else
  {
    dispatch_event_handler(dword_1198A8, v5);
    **(uint8_t **)off_11989C = 3;
  }
  rf_regf_high_check(v11);
  v7 = v11[0];
  v6[1] = v11[0];
  v8 = off_1198A0;
  if ( a2[1] )
    *((uint8_t *)off_1198A0 + 188) = (v7 & 0x20) != 0;
  else
    *((uint8_t *)off_1198A0 + 188) = (a2[2] & 0x20) != 0;
  if ( rf_get_reg0xf_bit20() )
  {
    v8[188] = 0;
    v9 = 0;
  }
  else
  {
    v9 = (uint8_t)v8[188];
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *((uint16_t *)v8 + 89) |= 0x4000u;
    dispatch_event_handler(dword_1198A4, v9);
    LOBYTE(v9) = v8[188];
  }
  *v6 = v9;
  rx_irq_handler(v6);
  return 0;
}

