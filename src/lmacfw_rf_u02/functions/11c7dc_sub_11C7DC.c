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

extern uint32_t dword_11C80C;
extern uint32_t dword_11C810;

// tx_slot_get_busy @ 0x11c7dc, size 48 bytes
int * tx_slot_get_busy(int a1)
{
  int v1; // r4
  int v2; // r6
  char v3; // r5
  int v4; // r7
  int v5; // r4
  int *result; // r0
  int v7; // r3

  v1 = dword_11C80C;
  v2 = dword_11C80C + 32 * a1;
  v3 = a1;
  v4 = 32 * a1;
  if ( *(uint8_t *)(v2 + 30) )
    ke_exit_critical(dword_11C80C + 32 * a1);
  v5 = v1 + v4;
  result = sub_100200((int *)v2, 0, 0x20u);
  v7 = dword_11C810;
  *(uint32_t *)(v5 + 8) = v2;
  *(uint8_t *)(v5 + 28) = v3;
  *(uint32_t *)(v5 + 4) = v7;
  return result;
}

