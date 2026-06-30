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

extern uint32_t dword_12AE38;
extern uint32_t dword_12AE3C;

// fmac_table_lookup @ 0x12ae04, size 52 bytes
// Doc: fmac_table_lookup [ke]: Indexed table lookup by id (entry size 32 bytes)
// fmac_table_lookup [ke]: Indexed table lookup by id (entry size 32 bytes)
int * fmac_table_lookup(int a1)
{
  int v1; // r4
  int v2; // r6
  char v3; // r5
  int v4; // r7
  int *result; // r0
  int v6; // r3
  int v7; // r1

  v1 = dword_12AE38;
  v2 = dword_12AE38 + 32 * a1;
  v3 = a1;
  v4 = 32 * a1;
  if ( *(uint8_t *)(v2 + 30) )
    timestamp_remove(dword_12AE38 + 32 * a1);
  result = memset_thunk((int *)v2, 0, 0x20u);
  v6 = v1 + v4;
  v7 = dword_12AE3C;
  *(uint32_t *)(v6 + 8) = v2;
  *(uint8_t *)(v6 + 28) = v3;
  *(uint32_t *)(v6 + 4) = v7;
  *(uint32_t *)(v6 + 24) = 3;
  return result;
}

