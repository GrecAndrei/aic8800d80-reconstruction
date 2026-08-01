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

extern uint32_t dword_13B5F4;
extern uint32_t dword_13B5F8;
extern uint32_t off_13B5FC;

// ll_ctl_terminate_ind @ 0x13b564, size 142 bytes
int  ll_ctl_terminate_ind(int a1, char *a2, unsigned int a3)
{
  unsigned int v5; // r5
  int v6; // r6
  char v7; // r0
  char v8; // r8
  uint8_t v9; // r7
  char v10; // r6
  uint8_t *v11; // r0

  if ( a2[2] != 2 )
    return 0;
  v5 = a3 >> 8;
  if ( rx_rate_field_parse(a3 & 0xFF00 | 8) == 4 )
  {
    v6 = dword_13B5F4 + 32 * v5;
    if ( *(uint8_t *)(v6 + 17) == 1 )
    {
      v7 = find_rates_ie(*(uint32_t *)(v6 + 28));
      v8 = *a2;
      v9 = a2[1];
      v10 = 4 - *(uint8_t *)(v6 + 20) + v7;
      v11 = (uint8_t *)ke_msg_alloc(5131, 13, 5, 3u);
      v11[2] = v10;
      *v11 = v8;
      v11[1] = v9;
      ke_msg_send((int)v11);
    }
    *(uint32_t *)(696 * (uint8_t)*a2 + 12 * (uint8_t)a2[1] + dword_13B5F8 + 448) = *((uint32_t *)off_13B5FC
                                                                                                 + 4);
    rf_set_channel(v5);
  }
  return 0;
}

