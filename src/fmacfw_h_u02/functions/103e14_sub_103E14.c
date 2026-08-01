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

extern uint32_t off_103E70;
extern uint32_t off_103E6C;
extern uint32_t dword_103E74;
extern uint32_t dword_103E78;
extern uint32_t off_103E80;
extern uint32_t dword_103E84;
extern uint32_t off_103E88;
extern uint32_t off_103E7C;
extern uint32_t dword_103E8C;

// tx_wait_ready @ 0x103e14, size 86 bytes
int tx_wait_ready()
{
  int v0; // r2
  int *v1; // r4
  int v2; // r0
  int v3; // r1
  int v4; // r2
  int *v5; // r3
  int v6; // r1
  uint32_t *v7; // r2
  int v8; // r0

  v0 = 777;
  v1 = (int *)off_103E70;
  *(uint32_t *)off_103E6C = 777;
  while ( *v1 < 0 )
    mmio_read32(1);
  alloc_tx_event(dword_103E74, *(uint32_t *)off_103E70, v0);
  v2 = dword_103E78;
  *(uint32_t *)off_103E6C = 0;
  alloc_tx_event(v2, v3, v4);
  v5 = (int *)off_103E80;
  v6 = dword_103E84;
  v7 = off_103E88;
  *(uint32_t *)off_103E7C = 0;
  *v5 = v6;
  v8 = dword_103E8C;
  *v7 &= 0xFF00FFFF;
  return alloc_tx_event(v8, 0x4000, v7);
}

