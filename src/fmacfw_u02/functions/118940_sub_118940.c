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

extern uint32_t off_1189EC;
extern uint32_t dword_1189F0;
extern uint32_t dword_1189F4;

// rf_tx_setup @ 0x118940, size 172 bytes
// Doc: sub_1218940 [util]: Helper with 3 args loading pointers from a 3-entry table (0x182b60/0x167bc0/0x167b74)
// sub_1218940 [util]: Helper with 3 args loading pointers from a 3-entry table (0x182b60/0x167bc0/0x167b74)
int  rf_tx_setup(int a1, int a2, int a3)
{
  int16_t **v3; // r8
  int v4; // r10
  int v5; // r9
  int v9; // r4
  int v10; // r1

  v3 = (int16_t **)off_1189EC;
  v4 = dword_1189F0;
  v5 = dword_1189F4;
  while ( 1 )
  {
    v9 = mem_word_load(a2);
    if ( !v9 )
      break;
    while ( 1 )
    {
      v10 = *(uint32_t *)(v9 + 76);
      if ( *(uint32_t *)(v9 + 68) )
      {
        *(uint32_t *)(v10 + 4) = 2080374784;
      }
      else if ( *(int *)(v10 + 4) >= 0 )
      {
        *(uint32_t *)(v10 + 4) = 0x40000000;
      }
      if ( *(uint16_t *)(v9 + 4) )
        break;
      free_buf_1882c0(v9);
      v9 = mem_word_load(a2);
      if ( !v9 )
        return tx_pool_init();
    }
    *(uint32_t *)(v10 + 4) |= 0x800000u;
    ll_state_check(v9, (uint32_t *)(v10 + 4));
    call_delayed_callback(v9);
    if ( ll_conn_tx_pdu_check(v9, 1) )
    {
      if ( **v3 < 0 && !a3 )
        mmio_clear_register(v5, v4, 1105);
      cmd_handler_a(a3);
    }
    else
    {
      save_context_args(a1, v9);
    }
  }
  return tx_pool_init();
}

