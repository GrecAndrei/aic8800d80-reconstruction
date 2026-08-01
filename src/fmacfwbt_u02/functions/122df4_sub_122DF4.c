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

extern uint32_t dword_122E5C;
extern uint32_t off_122E58;
extern uint32_t dword_122E64;
extern uint32_t dword_122E60;

// check_controller_ready @ 0x122df4, size 98 bytes
int  check_controller_ready(int a1, uint8_t *a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r4
  int v9; // r4
  int v10; // r3

  v4 = dword_122E5C;
  v6 = *a2;
  if ( **(int16_t **)off_122E58 < 0 && *(uint8_t *)(dword_122E5C + 1320 * v6 + 106) )
    mmio_irq_clear(dword_122E64, dword_122E60, 3702);
  v9 = v4 + 1320 * v6;
  *(uint8_t *)(v9 + 143) = a2[1];
  v10 = a2[2];
  *(uint16_t *)(v9 + 144) = (uint8_t)v10;
  hci_evt_alloc_send(134, a4, a3, v10);
  return 0;
}

