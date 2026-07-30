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

// phy_reg_init_n_2c4 @ 0x113310, size 148 bytes
// Doc: rf_msg_handler_3a2 [rf]: RF mailbox message handler
// rf_msg_handler_3a2 [rf]: RF mailbox message handler
int  phy_reg_init_n_2c4(int a1, int a2)
{
  uint8_t *v2; // r6
  int **v3; // r4
  char v4; // r0
  uint8_t *v5; // r12
  int *v6; // r7
  int *v7; // r5
  unsigned int v8; // r4
  int *v9; // r1
  char v10; // r3
  char v11; // r2
  uint16_t *v12; // r1
  int v13; // r2
  char v14; // r3

  v2 = rf_stream_start2_n158;
  if ( *(uint8_t *)rf_stream_start2_n158 )
    return -99;
  v3 = (int **)rf_stream_start2_n15c;
  v4 = list_count_d594(rf_stream_start2_n15c, a2);
  v5 = rf_msg_handler_n450;
  *(uint8_t *)rf_msg_handler_n450 = v4;
  if ( v4 )
  {
    v6 = *v3;
    v7 = *(int **)(rf_stream_start2_n160 + 8240);
    if ( v4 != 1 )
    {
      v8 = *((uint16_t *)v6 + 6);
      if ( *((uint16_t *)v7 + 6) < v8 )
      {
        v9 = v6;
        v10 = v4;
        while ( 1 )
        {
          v11 = v4 - v10--;
          if ( !v8 )
            break;
          if ( !*v9 || !v10 )
          {
            *v5 = v10;
            v7 = v9;
            goto log_free_dispatch_n215;
          }
          v8 = *(uint16_t *)(*v9 + 12);
          v7 = v9;
          v9 = (int *)*v9;
        }
        *v5 = v11;
      }
      goto log_free_dispatch_n215;
    }
    if ( v7 )
    {
log_free_dispatch_n215:
      v12 = (uint16_t *)v6[1];
      v13 = v7[1] + 8 * (*((uint8_t *)v7 + 14) - 1);
      v14 = *(uint8_t *)(v13 + 3);
      *v2 = 1;
      *(uint8_t *)(v13 + 3) = v14 & 0xF5 | 0xA;
      return sub_112E6C(1, v12);
    }
  }
  return -98;
}

