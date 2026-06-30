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

extern uint32_t dword_122028;
extern uint32_t dword_122018;
extern uint32_t dword_12201C;
extern uint32_t dword_122020;
extern uint32_t dword_122024;

// sub_121F44 @ 0x121f44, size 212 bytes
// Doc: rf_cmd_dispatch_fc0 [rf]: Dispatch incoming RF commands to handlers
// rf_cmd_dispatch_fc0 [rf]: Dispatch incoming RF commands to handlers
int  sub_121F44(int a1, int a2)
{
  unsigned int v4; // r5
  int v5; // r0
  int v7; // r3
  int cb_efa4; // r0
  int v9; // [sp+4h] [bp-4h]

  v4 = parse_int(*(uint8_t **)(a2 + 4), 0, 0x10u);
  if ( a1 <= 2 )
  {
    v5 = rf_cmd_dispatch_n_34(*(uint32_t *)a2);
    if ( v5 >= 0 )
      goto LABEL_3;
LABEL_18:
    sub_10DA6C(dword_122028, v5);
    return -1;
  }
  v9 = parse_int(*(uint8_t **)(a2 + 8), 0, 0);
  v5 = rf_cmd_dispatch_n_34(*(uint32_t *)a2);
  if ( v5 < 0 )
    goto LABEL_18;
  if ( v9 == 1 )
  {
LABEL_3:
    if ( ((v4 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      cb_efa4 = rf_reg_read_cb_efa4();
      sub_10DA6C(dword_122018, v4 & 0xFFFFFFFC, cb_efa4);
      return 0;
    }
    else if ( v5 == 4 )
    {
      sub_10DA6C(dword_12201C, v4, *(uint32_t *)v4);
      return 0;
    }
    else if ( v5 == 2 )
    {
      sub_10DA6C(dword_122020, v4, *(uint16_t *)v4);
      return 0;
    }
    else
    {
      if ( v5 == 1 )
        sub_10DA6C(dword_122024, v4, *(uint8_t *)v4);
      return 0;
    }
  }
  v7 = **(uint8_t **)a2 == 82 && v4 < 0x40000000;
  rf_mem_read_f594(v4, v9, (uint8_t)v5, v7);
  return 0;
}

