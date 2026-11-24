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


extern uint32_t off_124E18;
extern uint32_t off_124E1C;
extern uint32_t off_124E20;
extern uint32_t off_124E28;

// set_adv_data @ 0x124c70, size 424 bytes
int  set_adv_data(int a1, uint32_t *a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r7
  int v6; // r8
  int v7; // r0
  int v8; // r2
  uint8_t *v9; // r4
  int v10; // r1
  int v11; // r0
  int v12; // r0
  uint64_t result; // [sp+4h] [bp-14h] BYREF
  uint16_t a1a; // [sp+Ch] [bp-Ch] BYREF
  uint16_t a1_2; // [sp+Eh] [bp-Ah]
  int a3; // [sp+10h] [bp-8h]
  char v17; // [sp+16h] [bp-2h]

  mac_time_get(&result, 0);
  if ( a1 <= 1 )
  {
    dispatch_event_handler_1(asc_1301C8);
    return -1;
  }
  v4 = parse_number((uint8_t *)a2[1], nullptr, 0xAu);
  v5 = parse_number((uint8_t *)a2[2], nullptr, 0xAu);
  v6 = parse_number((uint8_t *)a2[3], nullptr, 0xAu);
  if ( a1 > 3 )
    v7 = parse_number((uint8_t *)a2[4], nullptr, 0xAu);
  else
    v7 = 0;
  if ( v4 == 5 )
  {
    a1a = (uint8_t)result;
    v17 = 0;
    a3 = HIDWORD(result);
    a1_2 = WORD2(result);
    rx_process_pending(0, (int)&a1a);
    set_reg_180800_bits7_8(0);
    v8 = 2;
  }
  else
  {
    if ( v4 == 10 )
    {
      a1a = (uint8_t)result;
      v17 = 0;
      a3 = HIDWORD(result);
      a1_2 = WORD2(result);
      rx_process_pending(0, (int)&a1a);
      set_reg_180800_bits7_8(0);
    }
    else
    {
      if ( (*(uint8_t *)off_124E18 & 8) == 0 && (v4 > 1 || v5 > 1) )
      {
        dispatch_event_handler_1("invalid bw:%d,%d\n", v4, v5);
        return -2;
      }
      a3 = HIDWORD(result);
      HIBYTE(a1a) = v4;
      LOBYTE(a1a) = result;
      v17 = 0;
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
              a1_2 = WORD2(result) + 30;
LABEL_14:
              rx_process_pending(0, (int)&a1a);
              set_reg_180800_bits7_8(v5);
              v8 = 0;
              goto LABEL_16;
            }
LABEL_25:
            a1_2 = WORD2(result) - 10;
            goto LABEL_14;
          }
          if ( v7 )
          {
            a1_2 = WORD2(result) - 30;
            goto LABEL_14;
          }
        }
        a1_2 = WORD2(result) + 10;
        goto LABEL_14;
      }
      a1_2 = WORD2(result);
      rx_process_pending(0, (int)&a1a);
      set_reg_180800_bits7_8(v5);
    }
    v8 = v4 == 10;
  }
LABEL_16:
  v9 = off_124E20;
  v10 = HIBYTE(a1a);
  v11 = (uint8_t)a1a;
  *(uint8_t *)off_124E1C = v8;
  *v9 = v8;
  clock_set_source(v11, v10, v8);
  dispatch_event_handler_1("\x9A\x88BW Set Done : prim freq %d, center freq %d\n", a1_2, (uint16_t)a3);
  v12 = *(uint32_t *)off_124E28;
  if ( *(uint32_t *)off_124E28 )
  {
    init_with_stack(v12);
    return 0;
  }
  return v12;
}
