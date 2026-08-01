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

extern uint32_t off_119724;
extern uint32_t dword_119728;

// ke_alloc_msg_0x74 @ 0x1196ac, size 120 bytes
// Doc: ke_alloc_msg_0x74 [ipc]: Build and send RF init message (op 0x74) via ipc_send
// ke_alloc_msg_0x74 [ipc]: Build and send RF init message (op 0x74) via ipc_send
int  ke_alloc_msg_0x74(int a1, int a2, int a3, int a4)
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
  v4 = (uint8_t *)ke_msg_send(116, a4, a3, 6);
  if ( (*(uint32_t *)off_119724 & 0x2000000) != 0 )
  {
    mmio_read_pair((int *)&v9, &v10);
    v6 = v9;
    v5 = v10;
  }
  else
  {
    memset(v11, 0, 6);
    bus_read_6((int)v11);
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
  v7 = dword_119728;
  v4[4] = BYTE1(v6);
  dispatch_event_handler(v7, HIBYTE(v5));
  rx_irq_handler(v4);
  return 0;
}

