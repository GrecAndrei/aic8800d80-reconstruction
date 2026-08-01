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

extern uint32_t off_128334;
extern uint32_t dword_128348;
extern uint32_t dword_128344;
extern uint32_t off_128338;
extern uint32_t dword_12833C;
extern uint32_t dword_128340;

// wifi_disable_action @ 0x128294, size 160 bytes
int  wifi_disable_action(int result)
{
  int v1; // r7
  int v2; // r5
  uint8_t *v3; // r6
  int v4; // r8
  int v5; // r0
  int16_t v6; // r5
  int16_t v7; // r4
  int v8; // r2

  v1 = *(uint32_t *)(result + 72);
  v2 = result;
  if ( **(int16_t **)off_128334 < 0 && !v1 )
    result = irq_disable_mmio_write(dword_128348, dword_128344, 3591);
  v3 = off_128338;
  if ( (*((uint8_t *)off_128338 + 88) & 0x20) == 0 && *((uint8_t *)off_128338 + 90) > 1u )
  {
    v4 = *(uint8_t *)(v2 + 116);
    v5 = tx_send_pdu(70, *((uint8_t *)off_128338 + 88) & 0x20, *((uint8_t *)off_128338 + 88) & 0x20, 20);
    *(uint8_t *)v5 = 0;
    *(uint8_t *)(v5 + 1) = *(uint8_t *)(v2 + 107);
    *(uint8_t *)(v5 + 2) = *(uint8_t *)(v1 + 4);
    *(uint8_t *)(v5 + 3) = *(uint8_t *)(v1 + 5);
    v6 = *(uint16_t *)(v1 + 8);
    v7 = *(uint16_t *)(v1 + 10);
    v8 = dword_12833C;
    *(uint16_t *)(v5 + 4) = *(uint16_t *)(v1 + 6);
    *(uint16_t *)(v5 + 6) = v6;
    *(uint16_t *)(v5 + 8) = v7;
    *(uint8_t *)(v5 + 16) = *(uint8_t *)(v1 + 12);
    *(uint32_t *)(v5 + 12) = (unsigned int)(((unsigned int)dword_128340
                                         * (unsigned uint64_t)(unsigned int)(*(uint32_t *)(v8 + 696 * v4 + 8) - 5000)) >> 32) >> 6;
    result = rx_process_packet(v5);
    v3[88] |= 0x20u;
  }
  return result;
}

