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

// llc_ccm_encrypt @ 0x11f3cc, size 122 bytes
int  llc_ccm_encrypt(int a1, int a2, int a3)
{
  int v3; // r10
  int v4; // r4
  int v8; // r9
  int v9; // r1
  int v10; // r0
  int v12; // [sp+4h] [bp-4h] BYREF

  v3 = *(uint32_t *)(a2 + 572);
  if ( !v3 )
    return 0;
  v4 = 0;
  v8 = a2 + 572;
  do
  {
    v12 = 0;
    if ( !isr_flag_dispatch(a1) )
      break;
    if ( !bt_is_link_active(v3) )
      break;
    v10 = bt_handle_state_event(a1, a2, &v12);
    if ( v12 )
      break;
    if ( !v10 )
      v10 = mem_word_load(v8);
    v9 = *(uint8_t *)(v10 + 27);
    *(uint8_t *)(v10 + 97) = 0;
    ++v4;
    phy_radio_init(v10, v9);
    if ( a3 )
    {
      if ( v4 == a3 )
        break;
    }
    v3 = *(uint32_t *)(a2 + 572);
  }
  while ( v3 );
  return v4;
}

