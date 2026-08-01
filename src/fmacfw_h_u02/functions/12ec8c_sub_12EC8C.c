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

extern uint32_t dword_12ECD0;

// pdu_alloc_424 @ 0x12ec8c, size 68 bytes
int  pdu_alloc_424(int a1, uint32_t *a2, int16_t a3, int16_t a4)
{
  uint32_t *v5; // r0
  int v6; // r1
  unsigned int v7; // r2
  int v8; // r4

  v5 = (uint32_t *)tx_send_pdu(1060, a4, a3, 0x408u);
  v7 = a2[1];
  v6 = *a2;
  if ( v7 >= 0x400 )
    v7 = 1024;
  *v5 = v6;
  v5[1] = v7;
  v8 = (int)v5;
  memcpy(v5 + 2, v6, v7);
  alloc_tx_event(dword_12ECD0, *a2, *(uint32_t *)(v8 + 4) + *a2, *(uint32_t *)(v8 + 8));
  rx_process_packet(v8);
  return 0;
}

