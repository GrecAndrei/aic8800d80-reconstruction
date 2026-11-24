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


extern uint32_t dword_10F69C;
extern uint32_t dword_10F6A0;
extern uint32_t off_10F698;

// mmio_write16 @ 0x10f5fc, size 156 bytes
uint64_t mmio_write16()
{
  uint16_t *v0; // r5
  int *v1; // r4
  int *v2; // r5
  int v3; // r6
  int *v4; // r1
  int v5; // r2
  uint64_t result; // r0
  uint32_t *v7; // r3

  v0 = off_10F698;
  v1 = (int *)dword_10F69C;
  *((uint16_t *)off_10F698 + 3080) = -16193;
  v0[1536] = -16193;
  *((uint8_t *)v0 + 6162) = 0;
  *((uint32_t *)v0 + 1541) = 0;
  *((uint8_t *)v0 + 6176) = 0;
  *((uint8_t *)v0 + 3074) = 0;
  *((uint32_t *)v0 + 769) = 0;
  list_init_1((uint32_t *)v0 + 770);
  list_init_1(v1 - 3);
  list_init_1(v1 + 512);
  list_init_1(v1 + 514);
  v0[4122] = 0;
  *((uint8_t *)v0 + 3074) = 0;
  *((uint32_t *)v0 + 769) = 0;
  memset_thunk(v1, 0, 0x800u);
  v2 = v1 + 512;
  v3 = (int)(v1 + 512);
  do
  {
    v4 = v1;
    v1 += 4;
    check_kernel_state(v3, v4);
  }
  while ( v1 != v2 );
  v5 = dword_10F6A0;
  result = (unsigned int)(dword_10F6A0 + 144);
  do
  {
    v7 = (uint32_t *)(v5 - 36);
    do
      *v7++ = 0;
    while ( v7 != (uint32_t *)v5 );
    v5 = (int)(v7 + 9);
  }
  while ( v7 + 9 != (uint32_t *)result );
  return result;
}
