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

extern uint32_t off_135160;
extern uint32_t dword_135164;

// bt_get_conn_params @ 0x1350d0, size 142 bytes
void  bt_get_conn_params(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  int v13; // r5
  uint8_t *v14; // r7
  int v17; // r1
  int v18; // r2
  int16_t v19; // r5

  v13 = *(uint32_t *)(a1 + 72);
  v14 = off_135160;
  check_status_bits(256, dword_135164, *((uint8_t *)off_135160 + 34), a2, (uint8_t)*(uint16_t *)(v13 + 108));
  if ( !v14[34] )
  {
    bt_setup_conn_profile(1, v17, v18, (uint8_t)v14[34], a5, a6, a7, a8, a9, a10, a11, a12, a13);
    return;
  }
  v19 = *(uint16_t *)(v13 + 108);
  if ( rx_rate_field_parse(6u) != 5 && rx_rate_field_parse(6u) != 8 )
  {
LABEL_5:
    v14[34] = 0;
    return;
  }
  if ( rx_rate_field_parse(6u) == 5 && (v19 & 0xFC) == 0xB0 || rx_rate_field_parse(6u) == 8 && (v19 & 0xDC) == 0 )
  {
    if ( (a2 & 0x800000) == 0 )
    {
      tx_path_status(a1, 5);
      *(uint8_t *)(a1 + 98) = 1;
      return;
    }
    goto LABEL_5;
  }
}

