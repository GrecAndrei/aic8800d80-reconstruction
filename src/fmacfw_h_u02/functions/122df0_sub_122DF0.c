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


extern uint32_t off_122E68;

// ke_send_msg_74 @ 0x122df0, size 120 bytes
int  ke_send_msg_74(int a1, int a2, uint16_t a3, uint16_t a4)
{
  uint8_t *v4; // r4
  uint16_t v5; // r3
  unsigned int v6; // r2
  unsigned int v8; // [sp+0h] [bp-14h] BYREF
  unsigned int a2a; // [sp+4h] [bp-10h] BYREF
  unsigned int v10[3]; // [sp+8h] [bp-Ch] BYREF

  v8 = 0;
  a2a = 0;
  v4 = (uint8_t *)tx_send_pdu(116, a4, a3, 6);
  if ( (*(uint32_t *)off_122E68 & 0x2000000) != 0 )
  {
    rf_cmd_8_write(&v8, &a2a);
    v6 = v8;
    v5 = a2a;
  }
  else
  {
    memset(v10, 0, 6);
    send_smc_cmd_0x400000((int)v10);
    v5 = __rev16(LOWORD(v10[0]));
    v6 = bswap32(*(unsigned int *)((char *)v10 + 2));
    v8 = v6;
    a2a = v5;
  }
  v4[1] = v5;
  v4[5] = v6;
  *v4 = HIBYTE(v5);
  v4[3] = BYTE2(v6);
  v4[2] = HIBYTE(v6);
  v4[4] = BYTE1(v6);
  alloc_tx_event(aGetMacaddrXX, HIBYTE(v5), (uint8_t)v6, HIBYTE(v6), v8, a2a);
  rx_process_packet_1((int)v4);
  return 0;
}
