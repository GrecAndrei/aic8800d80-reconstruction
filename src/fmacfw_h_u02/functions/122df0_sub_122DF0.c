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
extern uint32_t dword_122E6C;

// ke_send_msg_74 @ 0x122df0, size 120 bytes
int  ke_send_msg_74(int a1, int a2, int a3, int a4)
{
  uint8_t *v4; // r4
  uint16_t v5; // r3
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v9; // [sp+0h] [bp-14h] BYREF
  unsigned int v10; // [sp+4h] [bp-10h] BYREF
  unsigned int v11[3]; // [sp+8h] [bp-Ch] BYREF

  v9 = 0;
  v10 = 0;
  v4 = (uint8_t *)tx_send_pdu(116, a4, a3, 6);
  if ( (*(uint32_t *)off_122E68 & 0x2000000) != 0 )
  {
    rf_cmd_8_write(&v9, &v10);
    v6 = v9;
    v5 = v10;
  }
  else
  {
    memset(v11, 0, 6);
    send_smc_cmd_0x400000((int)v11);
    v5 = __rev16(LOWORD(v11[0]));
    v6 = bswap32(*(unsigned int *)((char *)v11 + 2));
    v9 = v6;
    v10 = v5;
  }
  v4[1] = v5;
  v4[5] = v6;
  *v4 = HIBYTE(v5);
  v4[3] = BYTE2(v6);
  v4[2] = HIBYTE(v6);
  v7 = dword_122E6C;
  v4[4] = BYTE1(v6);
  alloc_tx_event(v7, HIBYTE(v5), (uint8_t)v6);
  rx_process_packet(v4);
  return 0;
}

