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

extern uint32_t dword_10DF40;
extern uint32_t dword_10DF44;

// mmio_field_update @ 0x10df18, size 40 bytes
// Doc: mmio_field_update [mmio]: Updates a 2-bit field in a memory-mapped register using OR/BIC
// mmio_field_update [mmio]: Updates a 2-bit field in a memory-mapped register using OR/BIC
int  mmio_field_update(int a1)
{
  int v1; // r2
  int v2; // r0
  int v3; // r1

  v1 = dword_10DF40;
  v2 = 4 * a1;
  v3 = dword_10DF40 + 192;
  do
  {
    *(uint32_t *)(v1 - 12) = *(uint32_t *)(v1 - 12) & 0xFFFFFFF3 | v2;
    v1 += 12;
  }
  while ( v1 != v3 );
  return sub_102EB8(1, 16, 0x10u, dword_10DF44);
}

