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


extern uint32_t off_12EC58;
extern uint32_t off_12EC60;
extern uint32_t off_12EC64;
extern uint32_t off_12EC68;

// pdu_alloc_410 @ 0x12ebe0, size 118 bytes
int  pdu_alloc_410(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r1
  uint32_t *v7; // r4
  uint32_t *v9; // r2
  uint8_t *v10; // r0
  uint32_t *v11; // r3
  uint32_t *v12; // r3

  v5 = tx_send_pdu(1040, a4, a3, 4);
  v6 = *(uint16_t *)(a2 + 4);
  v7 = (uint32_t *)v5;
  if ( BYTE1(((uint32_t *)(uintptr_t)off_12EC58)[44]) )
  {
    if ( (unsigned int)(v6 - 1) > 1 )
      goto LABEL_3;
    v9 = off_12EC64;
    *(uint32_t *)off_12EC60 |= 0x2000000u;
    v10 = off_12EC68;
    v9[14] |= 0x10u;
    *v10 = 1;
  }
  if ( v6 == 1 )
  {
    v11 = off_12EC64;
    *((uint32_t *)off_12EC64 + 18) = *(uint32_t *)a2;
    v11[75] = 64;
    goto LABEL_5;
  }
LABEL_3:
  if ( v6 == 2 )
  {
    v12 = off_12EC64;
    *((uint32_t *)off_12EC64 + 19) = *(uint32_t *)a2;
    v12[75] = 128;
  }
LABEL_5:
  *v7 = 0;
  alloc_tx_event("\x9D\x81DBG: Boot NPC %d\n", v6);
  rx_process_packet_1((int)v7);
  return 0;
}
