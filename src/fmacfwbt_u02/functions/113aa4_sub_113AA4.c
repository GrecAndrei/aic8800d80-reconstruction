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


extern uint32_t dword_113BE4;
extern uint32_t dword_113BEC;
extern uint32_t dword_113BF4;
extern uint32_t dword_113C08;
extern uint32_t off_113BE8;
extern uint32_t off_113BF0;

// rx_packet_parse @ 0x113aa4, size 318 bytes
int  rx_packet_parse(int a1)
{
  unsigned int v1; // r3
  int v2; // r7
  int v4; // r8
  unsigned int v5; // r6
  uint32_t *v6; // r4
  int v7; // r1
  uint16_t v8; // r3
  uint16_t v9; // r2
  int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r2

  v1 = *(uint8_t *)(a1 + 25);
  v2 = *(uint8_t *)(a1 + 24);
  if ( v1 <= 0x1F && !*(uint8_t *)(dword_113BE4 + 696 * v1 + 37) )
  {
    ke_event_schedule_1(aPktDiscardSinc);
    return memory_pool_free((uint32_t *)(a1 - *off_113BF0 - 4));
  }
  v4 = dword_113C08;
  if ( (*(uint16_t *)(a1 + 26) & 8) == 0 )
  {
    if ( *(uint8_t *)(dword_113C08 + 1320 * v2 + 108) )
    {
      v5 = *(uint8_t *)(a1 + 22);
      if ( **(uint16_t **)off_113BE8 < 0 && v5 > 4 )
        mmio_irq_clear((int)aAcNxTxqCnt_0, (int)aHandleUsbRx, 926);
      v6 = scan_check_response();
      if ( v6 )
        goto LABEL_7;
LABEL_13:
      printf_wrapper(" host rx: dscr used = %d\r\n", *(uint8_t *)(dword_113BEC + v5));
      while ( 1 )
        ;
    }
    return memory_pool_free((uint32_t *)(a1 - *off_113BF0 - 4));
  }
  v5 = 3;
  v6 = scan_check_response();
  if ( !v6 )
    goto LABEL_13;
LABEL_7:
  v7 = v6[19];
  v8 = *((uint16_t *)v6 + 15) & 0xFFFE;
  ++*(uint8_t *)(dword_113BEC + v5);
  *((uint16_t *)v6 + 15) = v8;
  v6[17] = 0;
  *(uint32_t *)(v7 + 4) = 0;
  *(uint32_t *)(v7 + 72) = 0;
  v6[11] = 0;
  memcpy_aligned((char *)v6 + 4, (char *)a1, 0x1Cu);
  v9 = *((uint16_t *)v6 + 15);
  v10 = *off_113BF0;
  *((uint16_t *)v6 + 3) = 0;
  v6[18] = a1 - v10 - 4;
  *((uint8_t *)v6 + 66) = 0;
  v6[9] = 0;
  v6[21] = 0;
  *((uint16_t *)v6 + 41) = 0;
  *((uint16_t *)v6 + 15) = v9 & 0xFFFD;
  if ( (v9 & 8) != 0 )
    return check_abort_flag(v4 + 1320 * v2 + 1312, v6);
  v11 = *((uint8_t *)v6 + 29);
  if ( v11 <= 0x1F )
  {
    v12 = *((uint8_t *)v6 + 27);
    if ( v12 <= 8 )
      *(uint32_t *)(dword_113BF4 + 4 * (9 * v11 + v12 + 2062)) += *((uint16_t *)v6 + 2);
  }
  return check_abort_flag(v4 + 8 * (v5 + 165 * v2 + 154), v6);
}
