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

extern uint32_t off_13BCC4;
extern uint32_t dword_13BCD0;
extern uint32_t dword_13BCCC;
extern uint32_t dword_13BCC8;

// rf_set_frequency @ 0x13bc64, size 96 bytes
int  rf_set_frequency(int a1, int a2)
{
  unsigned int v2; // r5
  int *v5; // r4
  int v6; // r1
  int v7; // r3

  v2 = (uint16_t)((uint16_t)a2 << 8) | 8;
  v5 = (int *)tx_send_pdu(42, 0, ((uint16_t)a2 << 8) | 8, 3u);
  if ( **(int16_t **)off_13BCC4 < 0 && hci_cmd_handler(v2) != 4 )
    irq_disable_mmio_write(dword_13BCD0, dword_13BCCC, 891);
  v6 = dword_13BCC8 + 32 * a2;
  v7 = *(uint8_t *)(v6 + 17);
  v5[1] = a1;
  *v5 = v7 != 1;
  v5[2] = *(uint8_t *)(v6 + 22);
  return rx_process_packet((int)v5);
}

