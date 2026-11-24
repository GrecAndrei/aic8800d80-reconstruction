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


extern uint32_t dword_103E84;
extern uint32_t off_103E6C;
extern uint32_t off_103E70;
extern uint32_t off_103E7C;
extern uint32_t off_103E80;
extern uint32_t off_103E88;

// tx_wait_ready @ 0x103e14, size 86 bytes
int tx_wait_ready()
{
  int *v0; // r4
  int *v1; // r3
  int v2; // r1
  uint32_t *v3; // r2

  v0 = (int *)off_103E70;
  *(uint32_t *)off_103E6C = 777;
  while ( *v0 < 0 )
    mmio_read32(1);
  alloc_tx_event("end_addr=%d\n", *(uint32_t *)off_103E70);
  *(uint32_t *)off_103E6C = 0;
  alloc_tx_event(aFinish);
  v1 = (int *)off_103E80;
  v2 = dword_103E84;
  v3 = off_103E88;
  *(uint32_t *)off_103E7C = 0;
  *v1 = v2;
  *v3 &= 0xFF00FFFF;
  return alloc_tx_event("*0* dump    r 00100000 %d**\n", 0x4000);
}
