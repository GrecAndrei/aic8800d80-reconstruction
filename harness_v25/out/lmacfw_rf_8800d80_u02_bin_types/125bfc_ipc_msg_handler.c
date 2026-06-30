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

extern uint32_t dword_125D00;
extern uint32_t dword_125D0C;
extern uint32_t dword_125D14;
extern uint32_t dword_125D10;
extern uint32_t dword_125D04;
extern uint32_t dword_125D08;

// ipc_msg_handler @ 0x125bfc, size 258 bytes
// Doc: ipc_msg_handler [ipc]: Handles IPC message with payload parsing
// ipc_msg_handler [ipc]: Handles IPC message with payload parsing
int  ipc_msg_handler(int a1, uint8_t **a2)
{
  int v4; // r8
  int v5; // r4
  int v6; // r5
  int v7; // r6
  BOOL v9; // r0
  BOOL v10; // r0

  v4 = (*a2)[4];
  v5 = parse_int(a2[1], 0, 0);
  v6 = parse_int(a2[2], 0, 0);
  if ( v6 )
  {
    if ( a1 <= 3 )
      return -1;
    v7 = parse_int(a2[3], 0, 0);
    if ( v4 == 97 )
      goto LABEL_4;
  }
  else
  {
    v7 = 0;
    if ( v4 == 97 )
    {
LABEL_4:
      if ( v5 <= 15 )
      {
        bitmask_pow2_set(v5);
        if ( v6 )
        {
          rf_reg_bit_set(v5);
          if ( v7 )
            sub_10DB04(v5);
          else
            sub_10DB18(v5);
          msg_parse(dword_125D00, v5, v7);
          return 0;
        }
        else
        {
          mmio_clear_bit(v5);
          v10 = rf_check_bit(v5);
          msg_parse(dword_125D0C, v5, v10);
          return 0;
        }
      }
      msg_parse(dword_125D14, v5);
      return -2;
    }
  }
  if ( v5 > 15 )
  {
    msg_parse(dword_125D10, v5);
    return -2;
  }
  irq_prio_set_db48(v5);
  if ( !v6 )
  {
    sub_10DB78(v5);
    v9 = irq_mask_test(v5);
    msg_parse(dword_125D04, v5, v9);
    return v6;
  }
  irq_prio_set2(v5);
  if ( v7 )
    irq_enable(v5);
  else
    irq_disable(v5);
  msg_parse(dword_125D08, v5, v7);
  return 0;
}

