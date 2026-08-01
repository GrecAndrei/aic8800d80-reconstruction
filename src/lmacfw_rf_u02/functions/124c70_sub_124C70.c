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

extern uint32_t dword_124E2C;
extern uint32_t off_124E18;
extern uint32_t dword_124E30;
extern uint32_t off_124E20;
extern uint32_t off_124E1C;
extern uint32_t dword_124E24;
extern uint32_t off_124E28;

// set_adv_data @ 0x124c70, size 424 bytes
int  set_adv_data(int a1, uint8_t **a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r7
  int v6; // r8
  int v7; // r0
  int v8; // r2
  uint8_t *v9; // r4
  int v10; // r1
  int v11; // r0
  int result; // r0
  uint64_t v13; // [sp+4h] [bp-14h] BYREF
  uint8_t v14; // [sp+Ch] [bp-Ch] BYREF
  uint8_t v15; // [sp+Dh] [bp-Bh]
  uint16_t v16; // [sp+Eh] [bp-Ah]
  int v17; // [sp+10h] [bp-8h]
  char v18; // [sp+16h] [bp-2h]

  mac_time_get(&v13, 0);
  if ( a1 <= 1 )
  {
    dispatch_event_handler(dword_124E2C);
    return -1;
  }
  v4 = parse_number(a2[1], 0, 0xAu);
  v5 = parse_number(a2[2], 0, 0xAu);
  v6 = parse_number(a2[3], 0, 0xAu);
  if ( a1 > 3 )
    v7 = parse_number(a2[4], 0, 0xAu);
  else
    v7 = 0;
  if ( v4 == 5 )
  {
    v14 = v13;
    v15 = 0;
    v18 = 0;
    v17 = HIDWORD(v13);
    v16 = WORD2(v13);
    rx_process_pending(0, (int)&v14);
    set_reg_180800_bits7_8(0);
    v8 = 2;
  }
  else
  {
    if ( v4 == 10 )
    {
      v14 = v13;
      v15 = 0;
      v18 = 0;
      v17 = HIDWORD(v13);
      v16 = WORD2(v13);
      rx_process_pending(0, (int)&v14);
      set_reg_180800_bits7_8(0);
    }
    else
    {
      if ( (*(uint8_t *)off_124E18 & 8) == 0 && (v4 > 1 || v5 > 1) )
      {
        dispatch_event_handler(dword_124E30, v4, v5);
        return -2;
      }
      v17 = HIDWORD(v13);
      v15 = v4;
      v14 = v13;
      v18 = 0;
      if ( v4 )
      {
        if ( v4 == 1 )
        {
          if ( v6 )
            goto LABEL_25;
        }
        else
        {
          if ( !v6 )
          {
            if ( !v7 )
            {
              v16 = WORD2(v13) + 30;
LABEL_14:
              rx_process_pending(0, (int)&v14);
              set_reg_180800_bits7_8(v5);
              v8 = 0;
              goto LABEL_16;
            }
LABEL_25:
            v16 = WORD2(v13) - 10;
            goto LABEL_14;
          }
          if ( v7 )
          {
            v16 = WORD2(v13) - 30;
            goto LABEL_14;
          }
        }
        v16 = WORD2(v13) + 10;
        goto LABEL_14;
      }
      v16 = WORD2(v13);
      rx_process_pending(0, (int)&v14);
      set_reg_180800_bits7_8(v5);
    }
    v8 = v4 == 10;
  }
LABEL_16:
  v9 = off_124E20;
  v10 = v15;
  v11 = v14;
  *(uint8_t *)off_124E1C = v8;
  *v9 = v8;
  clock_set_source(v11, v10, v8);
  dispatch_event_handler(dword_124E24, v16, (uint16_t)v17);
  result = *(uint32_t *)off_124E28;
  if ( *(uint32_t *)off_124E28 )
  {
    init_with_stack(result);
    return 0;
  }
  return result;
}

