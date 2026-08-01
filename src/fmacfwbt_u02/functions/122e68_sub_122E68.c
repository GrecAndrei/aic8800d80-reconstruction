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

extern uint32_t dword_122EC8;
extern uint32_t off_122EC4;
extern uint32_t dword_122ED0;
extern uint32_t dword_122ECC;

// get_controller_state @ 0x122e68, size 92 bytes
int  get_controller_state(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r5
  int v9; // r0
  int v10; // r3

  v4 = dword_122EC8;
  v6 = *a2;
  if ( **(int16_t **)off_122EC4 < 0 && *(uint8_t *)(dword_122EC8 + 1320 * v6 + 106) )
    mmio_irq_clear(dword_122ED0, dword_122ECC, 2639);
  v9 = v4 + 1320 * v6;
  *(uint16_t *)(v9 + 112) = *((uint16_t *)a2 + 1);
  v10 = a2[4];
  *(uint8_t *)(v9 + 114) = v10;
  hci_evt_alloc_send(76, a4, a3, v10);
  return 0;
}

