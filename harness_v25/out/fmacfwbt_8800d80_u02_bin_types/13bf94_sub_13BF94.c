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

extern uint32_t dword_13BFFC;
extern uint32_t dword_13C00C;
extern uint32_t dword_13C010;
extern uint32_t dword_13C000;
extern uint32_t dword_13C004;
extern uint32_t dword_13C008;

// sub_13BF94 @ 0x13bf94, size 104 bytes
// Doc: sub_123BF94 [ipc]: Looks up table entry by 32-byte slot index, bounded to 16 entries
// sub_123BF94 [ipc]: Looks up table entry by 32-byte slot index, bounded to 16 entries
int  sub_13BF94(unsigned int a1)
{
  int v1; // r5
  int v2; // r6
  int v3; // r7
  int v5; // r8
  int v6; // r0
  int v7; // r4

  v1 = dword_13BFFC;
  v2 = dword_13BFFC + 32 * a1;
  v3 = *(uint8_t *)(v2 + 16);
  v5 = 32 * a1;
  if ( a1 <= 0xF )
  {
    list_remove_node_d510(dword_13C00C, (uint32_t *)v2);
    list_push_tail(dword_13C010, (uint32_t *)v2);
  }
  else
  {
    list_remove_node_d510(dword_13C000, (uint32_t *)v2);
    list_push_tail(dword_13C004, (uint32_t *)v2);
  }
  v6 = (a1 << 8) & 0xFF00;
  v7 = dword_13C008;
  rf_bus_mark_n_3b7(v6 | 8, 4);
  *(uint8_t *)(v1 + v5 + 25) = 0;
  return rf_bus_write_n_25c(v3, v2, 2, 0, 0, 39, v7);
}

