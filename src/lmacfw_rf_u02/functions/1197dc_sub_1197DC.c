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


extern uint32_t off_11989C;
extern uint32_t off_1198A0;

// ke_alloc_msg_0x7c @ 0x1197dc, size 186 bytes
int  ke_alloc_msg_0x7c(int a1, uint8_t *a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v5; // r5
  int v6; // r2
  int v7; // r6
  unsigned int v8; // r7
  int v9; // r1
  int v11; // r2
  uint8_t a1a[5]; // [sp+7h] [bp-5h] BYREF

  a1a[0] = 0;
  v5 = (uint8_t *)ke_msg_send_1(124, a4, a3, 2);
  if ( *a2 )
  {
    dispatch_event_handler_1(aDriverStart);
    **(uint8_t **)off_11989C = 0;
  }
  else
  {
    dispatch_event_handler_1(aDriverStop);
    **(uint8_t **)off_11989C = 3;
  }
  rf_regf_high_check(a1a);
  v6 = a1a[0];
  v5[1] = a1a[0];
  if ( a2[1] )
  {
    v7 = off_1198A0;
    *(uint8_t *)(off_1198A0 + 0xBC) = (v6 & 0x20) != 0;
    v8 = ((v6 ^ 0x40u) >> 6) & 1;
  }
  else
  {
    v11 = (uint8_t)a2[2];
    v7 = off_1198A0;
    v8 = ((v11 ^ 0x40u) >> 6) & 1;
    *(uint8_t *)(off_1198A0 + 0xBC) = (v11 & 0x20) != 0;
  }
  if ( rf_get_reg0xf_bit20() )
  {
    *(uint8_t *)(v7 + 0xBC) = 0;
    v9 = 0;
  }
  else
  {
    v9 = *(uint8_t *)(v7 + 0xBC);
  }
  if ( *a2 )
  {
    if ( a2[3] )
      *(uint16_t *)(v7 + 0xB2) |= 0x4000u;
    dispatch_event_handler_1("is 5g=%d, sw_en=%d, vendor_info=0x%x\r\n", v9, v8, a1a[0]);
    LOBYTE(v9) = *(uint8_t *)(v7 + 0xBC);
  }
  *v5 = v9;
  rx_irq_handler_1((int)v5);
  return 0;
}
