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

extern uint32_t off_131A5C;

// bt_pkt_check @ 0x1319d0, size 138 bytes
int  bt_pkt_check(int a1, uint8_t *a2, unsigned int a3, int16_t a4)
{
  uint32_t *v5; // r5
  int v6; // r7
  int v8; // r0
  int v9; // r0
  int v10; // r3
  uint8_t *v12; // r0
  int v13; // r3
  char v14; // r3
  unsigned int v15; // [sp+4h] [bp-8h]

  v5 = off_131A5C;
  v6 = *((uint32_t *)off_131A5C + 1);
  v8 = 1 << a2[1];
  if ( *a2 )
    v9 = v8 | v6;
  else
    v9 = v6 & ~v8;
  v10 = *((uint8_t *)off_131A5C + 375);
  *((uint32_t *)off_131A5C + 1) = v9;
  if ( !v10 )
    goto LABEL_7;
  v15 = a3;
  if ( rx_rate_field_parse(5u) == 1 )
    return 2;
  LOWORD(a3) = v15;
  if ( (uint8_t)v6 )
  {
    if ( *a2 )
    {
LABEL_7:
      ke_msg_send_no_param(5146, a4, a3);
      return 0;
    }
  }
  else if ( !*a2 )
  {
    goto LABEL_7;
  }
  v12 = (uint8_t *)ke_msg_alloc(49, 0, v15, 1u);
  v13 = v5[1];
  *((uint16_t *)v5 + 4) = a4;
  if ( v13 )
    v14 = 0;
  else
    v14 = *((uint8_t *)v5 + 376);
  *v12 = v14;
  ke_msg_send((int)v12);
  rx_phy_status_parse(v15, 1);
  return 0;
}

